from os import listdir
from os.path import isdir

def filesindir(path: str) -> list[str]:
   return [f"{path}/{y}" for y in filter(lambda x: not isdir(f"../{path}/{x}") and x.endswith(".h"), listdir(f"../{path}"))]

directories = ["include", "include/types", "include/types/intro", "include/level"]
dirlist = []
for d in directories:
   dirlist.extend(filesindir(d))

with open("../ctx.h", "w") as f:
   f.writelines([f"#include \"{x[8:]}\"\n" for x in dirlist])
