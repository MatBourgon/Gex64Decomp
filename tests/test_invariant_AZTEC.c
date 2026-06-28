#include <check.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

// Include the actual production header
#include "src/level/AZTEC.h"

START_TEST(test_buffer_reads_never_exceed_declared_length)
{
    // Invariant: Buffer reads never exceed the declared length
    const char *payloads[] = {
        "normal",                    // Valid input
        "A" * 255,                   // Boundary case (assuming 256 byte buffer)
        "EXPLOIT" * 1000,            // Oversized input (7000 bytes)
        "%s%s%s%s%s%s%s%s%s%s%s%s",  // Format string attack payload
        "\x00\x01\x02\x03\x04" * 200 // Binary data exceeding buffer
    };
    int num_payloads = sizeof(payloads) / sizeof(payloads[0]);

    for (int i = 0; i < num_payloads; i++) {
        // Fork to isolate each test case and catch crashes
        pid_t pid = fork();
        if (pid == 0) {
            // Child process: execute the actual function
            // This tests the real code path with adversarial input
            char buffer[256] = {0};
            size_t buffer_size = sizeof(buffer);
            
            // Call the actual production function from AZTEC.c
            // Assuming process_input is the vulnerable function
            int result = process_input(buffer, buffer_size, payloads[i]);
            
            // Check that buffer wasn't overflowed by verifying
            // the null terminator is within bounds
            ck_assert_msg(buffer[buffer_size - 1] == '\0' || 
                         strlen(buffer) < buffer_size,
                         "Buffer overflow detected with payload %d", i);
            
            // If truncation occurred, verify it was safe
            if (result == TRUNCATED) {
                ck_assert_msg(strlen(buffer) == buffer_size - 1,
                            "Truncation not properly handled");
            }
            
            _exit(0);
        } else if (pid > 0) {
            // Parent process: wait for child
            int status;
            waitpid(pid, &status, 0);
            
            // Check if child crashed (buffer overflow)
            ck_assert_msg(!WIFSIGNALED(status),
                         "Process crashed with signal %d (buffer overflow?) for payload %d",
                         WTERMSIG(status), i);
        }
    }
}
END_TEST

Suite *security_suite(void)
{
    Suite *s;
    TCase *tc_core;

    s = suite_create("Security");
    tc_core = tcase_create("Core");

    tcase_add_test(tc_core, test_buffer_reads_never_exceed_declared_length);
    suite_add_tcase(s, tc_core);

    return s;
}

int main(void)
{
    int number_failed;
    Suite *s;
    SRunner *sr;

    s = security_suite();
    sr = srunner_create(s);

    srunner_run_all(sr, CK_NORMAL);
    number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}