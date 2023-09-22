import os
import sys
import pathlib
import zipfile
dirName=input("enter directory name that you want to backup:")
if not os.path.isdir(dirName):
    print("no such file or directory")
    sys.exit(0)
curDirectory=pathlib.Path(dirName)
with zipfile.ZipFile("abc.zip",mode="w")as archive:
    for file_path in curDirectory.rglob("*"):
        archive.write(file_path,arcname=file_path.relative_to(curDirectory))

if os.path.isfile("abc.zip"):
    print("archive","abc.zip","created successfulluy")
else:
    print("error creating the archive")