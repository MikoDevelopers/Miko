import subprocess
import time
import sys

"""
    *  builder.py -c, -C    only compile
    *  builder.py -r, -R    run exe-file
    *  builder.py -a, -A    start compile and after run compiled file
    *  builder.py -v, -V    show version of this program
    *  builder.pu -d, -D    start grogram with debug-mode(show time of working program)
"""


def showTime(func):
    def wrapper():
        startTime = time.time()
        func()
        endTime = time.time() - startTime
        print(f"\n\n------------------------------------\n\tTime: {endTime}")

    return wrapper


class Builder:
    def __init__(self):
        ...

    @staticmethod
    def compile_():
        print("Start compile...")

        subprocess.call(f"{COMPILER} {' '.join(CPP_FILES)} -o {EXE_FILE}")
        
        print("Complie process is ended...")
    
    @staticmethod
    def run(filename = "main.miko"):
        print("\nStart programm...\n------------------------\n\n")

        subprocess.call(f"{EXE_FILE} {filename}")

    @staticmethod
    @showTime
    def compile_run():
        Builder.compile_()
        Builder.run()


__version__ = 1.2
AVAILBL_ARGS = {
    "-C" : Builder.compile_,                                         # mode for only compile choised cpp-files
    "-R" : Builder.run,                                              # mode for run compiled programm
    "-A" : Builder.compile_run,                                      # compile programm and start
    "-V" : lambda: print(f"Version: {__version__}"),         # show version 
}
ARGS = sys.argv
COMPILER = "g++"                               # name of compiler
CPP_FILES = [
    "main.cpp",
    "Analizator/CodeAnalizer.cpp",
    "Read/ReadMikoFile.cpp",
]
EXE_FILE = "main"                              # output exe-file



AVAILBL_ARGS.get(ARGS[1])()                    # choice mode for program and start with choiced mode(s)