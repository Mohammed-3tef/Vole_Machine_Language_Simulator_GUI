# Vole Machine Language Simulator GUI

## Table of Contents

- [📌 Introduction](#-introduction)
- [🚀 Features](#-features)
- [🖼️ Screenshots](#-screenshots)
- [🛠️ Getting Started](#-getting-started)
  - [📋 Prerequisites](#-prerequisites)
  - [📥 Installation](#-installation)
  - [📥 Download the Latest Release](#-download-the-latest-release)
- [📌 Usage](#-usage)
- [📁 Project Structure](#-project-structure)
- [🤝 Contributing](#-contributing)
- [🌟 Acknowledgments](#-acknowledgments)
- [🖥️ Console Version](#️-console-version)
- [📜 License](#-license)

## 📌 Introduction

The Vole Machine Language Simulator GUI is a graphical application designed to simulate the operations of a simple CPU. Built with Qt, it provides users with the ability to load instructions, view and edit memory, monitor register states, and perform operations such as fetch, decode, and execute. This tool is intended for educational purposes, aiding in the understanding of basic CPU functionality and object-oriented programming principles.

## 🚀 Features

- **Memory Management**: Visual representation of memory cells, supporting hexadecimal, binary, and integer views.
- **Register Management**: Display and management of registers with detailed formats.
- **Instruction Execution**: Load, decode, fetch, and execute instructions with step-by-step control.
- **Manual Instruction Input**: Option to manually add, decode, and execute instructions without fetching from memory.
- **User Interface**: Intuitive Qt-based GUI with a dedicated 'How to Use' window for user guidance.
- **Cross-Platform Compatibility**: Runs on Windows, macOS, and Linux.

## 🖼️ Screenshots



## 🛠️ Getting Started

### 📋 Prerequisites

- **Qt Framework**: Ensure that Qt (version 5 or later) is installed on your system.
- **C++ Compiler**: A compatible C++ compiler is required.
- **CMake**: Optional, if you prefer using CMake as the build system.

### 📥 Installation

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/esraa-emary/Vole-Machine-Language-Simulator-GUI.git
   cd Vole-Machine-Language-Simulator-GUI
   ```

2. **Build the Project**:
   - Ensure that CMake and Qt are installed.
   - Create a build directory:
     ```bash
     mkdir build && cd build
     ```
   - Run CMake:
     ```bash
     cmake ..
     ```
   - Compile the project:
     ```bash
     make
     ```

3. **Run the Application**:
   ```bash
   ./Vole-Machine-Language-Simulator
   ```

### 📥 Download the Latest Release

Get the latest version of **Vole Machine Language Simulator GUI**: [Download Here](https://github.com/esraa-emary/Vole-Machine-Language-Simulator-GUI/releases/latest) <br>
Visit the release page to download the precompiled binaries for your system. Extract the downloaded file and run the executable to start using the simulator!

## 📌 Usage

1. **Load Instruction File**: Use the 'Open Instruction File' button to load a Vole machine code file in `.txt` format.
2. **Fetch and Decode**: Click 'Fetch' to load the instruction into the Instruction Register, then click 'Decode' to parse it.
3. **Execute**: Use the 'Execute' button to run the decoded instruction, updating memory and registers accordingly.
4. **Control Execution**:
   - 'Run One Cycle': Execute a single instruction cycle.
   - 'Run Until Halt': Continuously execute instructions until a halt condition is met.
5. **Reset and Clear**: Options are available to reset the program counter or clear memory and registers as needed.

## 📁 Project Structure


## 🤝 Contributing

Contributions are welcome! To contribute:

1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes, ensuring adherence to the project's coding style.
4. Commit your changes with clear and concise commit messages.
5. Push your changes to your forked repository.
6. Submit a pull request detailing your changes and the motivation behind them.

Please ensure that your contributions include relevant documentation and, if applicable, update existing documentation to reflect your changes.

## 🌟 Acknowledgments

We would like to thank our professor, Dr. Mohamed El-Ramly, for his guidance and support throughout this project and our academic journey. We are grateful for the opportunity to work on this project and develop our programming skills.

## 🖥️ Console Version

Prefer the classic console-based experience? Check out the **Vole Machine Simulator Console Version**: [Console Version Repository](https://github.com/esraa-emary/Vole-Machine-Language-Simulator)

## 📜 License

This project is licensed under the Mozilla Public License 2.0. See the [LICENSE](https://github.com/esraa-emary/Vole-Machine-Language-Simulator-GUI/blob/main/LICENSE) file for more details.

## Have fun exploring the Vole Machine Language Simulator GUI! Let us know your thoughts and feedback!! 🎉🤖
