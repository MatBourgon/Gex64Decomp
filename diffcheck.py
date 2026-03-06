original, new = None, None
with open("gex64.z64", "rb") as f:
    original = f.read()
with open("rom.z64", "rb") as f:
    new = f.read()

diffFound = None

try:
    for i in range(0, 0x1_000_000, 4):
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

if not diffFound:
    print("No differences found!")
    exit(0)
else:
    print(diffFound)
    exit(1)