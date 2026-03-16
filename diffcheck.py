import threading, datetime

__start = datetime.datetime.now()

original, new = None, None
with open("gex64.z64", "rb") as f:
    original = f.read()
with open("rom.z64", "rb") as f:
    new = f.read()

threads = []

romSize = 0x1_000_000
unitSize = 0x100_000
unitCount = romSize // unitSize
threadResults = [None] * unitCount

def CheckSection(index):
    start = unitSize * index
    end = start + unitSize
    diffFound = None

    try:
        for i in range(start, end, 4):
            oB = original[i:i+4]
            nB = new[i:i+4]
            d = 0
            for j in range(4):
                if oB[j] != nB[j]:
                    d += 1
            if d == 4:
                diffFound = f"Major Difference at: {hex(i)}"
                break
            elif d > 0:
                diffFound = f"Minor Difference at: {hex(i)}"
    except:
        diffFound = "Error diffing! Maybe file sizes are different?"

    threadResults[index] = diffFound

for i in range(unitCount):
    threads.append(threading.Thread(target=CheckSection, args=(i,)))

for t in threads:
    t.start()

for t in threads:
    t.join()

fail = False

totalTime = datetime.datetime.now() - __start

for i, r in enumerate(threadResults):
    if r != None:
        fail = True
        print(f"[{"0x{:06X}".format(unitSize * i)}-{"0x{:06X}".format(unitSize * (i + 1))}]: {r}")

if fail:
    print(f"Differences found. [{(totalTime).total_seconds()}s]")
    exit(1)
else:
    print(f"No differences found! [{(totalTime).total_seconds()}s]")
    exit(0)
