# R001

R001 is a cross-platform system recovery and security research utility written in C.

## Notice

This project is intended for:

- Security research
- System recovery
- Vulnerability analysis
- Educational purposes

Only use R001 on systems that you own or are explicitly authorized to test.

## Platform Support

| Platform | Status |
|----------|--------|
| Linux | Supported |
| Windows | Supported |

## Requirements

### Linux

- GCC or Clang
- Make (optional)

### Windows

One of the following:

- Visual Studio 2022+
- MSVC Build Tools
- MinGW-w64
- Clang

## Building

### Linux (GCC)

```bash
gcc -O2 -Wall -Wextra -o r001 src/*.c
```

### Linux (Clang)

```bash
clang -O2 -Wall -Wextra -o r001 src/*.c
```

### Windows (MSVC)

```cmd
cl /O2 /W4 src\*.c /Fe:r001.exe
```

### Windows (MinGW-w64)

```bash
gcc -O2 -Wall -Wextra src/*.c -o r001.exe
```

### Windows (Clang)

```bash
clang -O2 -Wall -Wextra src/*.c -o r001.exe
```

## Debug Builds

### Linux

```bash
gcc -g -O0 -Wall -Wextra -o r001 src/*.c
```

### Windows (MSVC)

```cmd
cl /Zi /Od src\*.c /Fe:r001.exe
```

## Project Layout

```text
R001/
├── main.d
├── Exploits/
```

## Reporting Issues

When opening an issue, please include:

- Operating system
- Architecture (x86, x64, ARM64)
- Compiler and version
- Build command used
- Complete error output

## Disclaimer

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.

Use of this software is entirely at your own risk. The authors assume no responsibility for misuse, damage, data loss, service interruption, or legal consequences resulting from its use.

## License

- MIT
