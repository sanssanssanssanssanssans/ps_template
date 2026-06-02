import os
import subprocess
import sys
import time

CPP = "main/solve.cpp"
EXE = "main/solve.exe" if os.name == "nt" else "./main"
INPUT = "main/test/input.txt"
OUTPUT = "main/test/output.txt"
ANSWER = "main/test/answer.txt"
CMD = [
    "g++",
    CPP,
    "-O2",
    "--std=c++17",
    "-Wall",
    "-o",
    "solve.exe" if os.name == "nt" else "main",
]


def norm(s: str) -> str:
    return "\n".join(line.strip() for line in s.strip().splitlines())


def read(path: str) -> str:
    with open(path, "r", encoding="utf-8") as file:
        return file.read()


def compile() -> None:
    print("[*] Compiling...")
    result = subprocess.run(CMD, capture_output=True, text=True)
    if result.returncode != 0:
        print(f"[!] Compilation failed: {result.stderr}")
        sys.exit(1)
    print("[*] Compiled successfully.")


def run() -> None:
    print("[*] Running...")
    with open(INPUT, "r", encoding="utf-8") as file:
        start = time.perf_counter()
        result = subprocess.run([EXE], stdin=file, capture_output=True, text=True)
        end = time.perf_counter()
    with open(OUTPUT, "w", encoding="utf-8") as file:
        file.write(result.stdout)
    if result.returncode != 0:
        print(f"[!] Execution failed: {result.stderr}")
        sys.exit(1)
    print(f"[*] Ran successfully in {(end - start) * 1000:.2f}s.")


def compare() -> None:
    out = norm(read(OUTPUT))
    ans = norm(read(ANSWER))
    print()
    if out != ans:
        print("[!] Output does not match answer.")
        sys.exit(1)
    print("[*] Output matches answer.")


def main() -> None:
    compile()
    run()
    compare()


main()
