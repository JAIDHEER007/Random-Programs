import psutil
import random
import string

def getRandomStr(size: int) -> str:
    return ''.join([random.choice(string.ascii_letters) for _ in range(size)])

print("Select File Size Unit")
print("1. Bytes")
print("2. KiloBytes")
print("3. MegaBytes")
print("4. GigaBytes")

sOpt = int(input("Enter option: "))

totalBytes = 0
procced = True

if sOpt == 1:
    totalBytes = int(input("Enter number of bytes: "))
elif sOpt == 2:
    totalBytes = int(input("Enter number of KiloBytes: ")) * 1024
elif sOpt == 3:
    totalBytes = int(input("Enter number of MegaBytes: ")) * 1024 * 1024
elif sOpt == 4:
    totalBytes = int(input("Enter number of GigaBytes: ")) * 1024 * 1024 * 1024
else:   
    print("Enter a valid option")
    procced = False

if procced:
    print(totalBytes)
    allowedRam = (psutil.virtual_memory()[4] // 7)
    print("Allowed RAM Slice: {memory} MB".format(memory = str(allowedRam / (1024 * 1024))))

    wParts = totalBytes //  allowedRam
    fPart = totalBytes % allowedRam

    print(wParts)
    print((fPart))

    # for _ in range(wParts):
    #     print(len(getRandomStr(allowedRam)))