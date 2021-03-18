from Cython.Build import cythonize
from distutils.core import setup


setup(ext_modules = cythonize("lib.pyx"))
#python setup.py build_ext --inplace