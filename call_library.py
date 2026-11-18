import ctypes
from pathlib import Path

# Load the shared library built from mathlib.c.
library_path = Path(__file__).with_name("libmathlib.so")
mathlib = ctypes.CDLL(str(library_path))

mathlib.square_value.argtypes = [ctypes.c_double]
mathlib.square_value.restype = ctypes.c_double

value = 6.5
print(f"Square of {value} = {mathlib.square_value(value):.2f}")
