import subprocess
import sys

# builder.py -C
# builder.py -R
# builder.py -A
# builder.py -V


def compile_():
    print("Start compile...")

    subprocess.call(f"{COMPILER} {' '.join(CPP_FILES)} -o {EXE_FILE}")
    
    print("Complie process is ended...")


def run():
    print("\nStart programm...\n------------------------\n\n")
    
    subprocess.call(EXE_FILE)


def compile_run():
    compile_()
    run()



__version__ = 1.2
AVAILBL_ARGS = {
    "-C" : compile_,                                         # mode for only compile choised cpp-files
    "-R" : run,                                              # mode for run compiled programm
    "-A" : compile_run,                                      # compile programm and start
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



AVAILBL_ARGS.get(ARGS[1])()