# ChaosRam 
# Educational Malware Project Sample

⚠️ **WARNING: The code in this project represents malware examples created for educational purposes only** ⚠️

Using this code on computer systems without proper authorization may be illegal and could cause damage to those systems.

## Project Description

This project demonstrates techniques that malware might employ, including:

1. **Memory Exhaustion Attack** (allocations.cpp)
2. **Persistence Through Auto-Start** (setpath.cpp)
3. **Obfuscation Through Encryption** (XORfile.cpp)
4. **Runtime Decryption and Code Assembly** (main.cpp)

## Files in the Project

- **allocations.cpp**: Code that continuously allocates memory without releasing it
- **setpath.cpp**: Code that adds itself to the Windows startup programs list
- **XORfile.cpp**: Code for encrypting files using the XOR technique
- **main.cpp**: Code that decrypts, combines, and compiles the malware components

## Educational Objectives

This project is designed to help understand:
- Methods malware uses to infiltrate systems
- Basic encryption and decryption techniques
- Windows autostart mechanisms
- Resource exhaustion attack techniques

## Safe Usage Guidelines

If you wish to examine this code, please follow these guidelines:
- Only use it in an isolated virtual machine environment separate from your main system
- It is not recommended to directly compile and run allocations.cpp and setpath.cpp
- Use the code only for analytical and educational purposes

## Caution

Potential effects of running this code include:
- Complete exhaustion of system memory
- Significant system slowdown or freezing
- Automatic execution upon every system startup

## Disclaimer

The publisher of this code takes no responsibility for any damage that may result from misuse or inappropriate application of this code.

---

This project is intended solely for cybersecurity education and understanding. It is not intended for malicious use.

## License
MIT License