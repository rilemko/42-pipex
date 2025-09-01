<a id="readme-top" name="readme-top"></a>

<!-- ------------------------------
* TITLE, DESCRIPTION & CONTACT
------------------------------ -->
# 🧪 pipex

<table>
    <tr>
        <th align="left" width="3333px">Score</th>
        <th align="left" width="3333px">Duration</th>
        <th align="left" width="3333px">Peer(s)</th>
    </tr>
    <tr>
        <td>✅ <b>125</b> / 100</td>
        <td>🕓 2 week(s)</td>
        <td>👷🏻 No</td>
    </tr>
</table>

<br>

This project is a program designed to reproduce the behavior of a **shell command line**. Taking as arguments an input file (or an implemented heredoc-style input), at least two commands and an output file, it uses the **UNIX API** with **pipes**, **forks** and **file descriptor manipulation** to find and execute binaries and pass data from one to the other.

[**⛓️ FILE : SUBJECT**](en.subject.pdf)

<br>

<!-- ------------------------------
* TABLE OF CONTENTS
------------------------------ -->
## 📋 Table of contents

- [**👀 Overview**](#readme-overview)
- [**📦 Requirements**](#readme-requirements)
- [**💾 Installation**](#readme-installation)
- [**⚡️ Usage**](#readme-usage)
- [**🛠️ Makefile**](#readme-makefile)
- [**📄 License**](#readme-license)

<a id="readme-overview" name="readme-overview"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* OVERVIEW
------------------------------ -->
## 👀 Overview

### Features

- Supports two or more commands.
- Supports commands by basename, absolute path or relative path.
- Search order for binaries identical to a shell.
- Executes the correct binaries and passes the data from one to the other.
- Supports files as input.
- Implements heredoc-style input.

<a id="readme-requirements" name="readme-requirements"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* REQUIREMENTS
------------------------------ -->
## 📦 Requirements

```
sudo apt -y install clang-12 make
```

<a id="readme-installation" name="readme-installation"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* INSTALLATION
------------------------------ -->
## 💾 Installation

**1. Get the project**

```
git clone https://github.com/rilemko/42-pipex.git
```

<br>

**2. Build the project**

```
make -j$(nproc)
```

> **🔵 Info:** The `pipex` executable will be created in the project root directory.

<br>

**3. Run the project**

```
./pipex <infile> <command1> <command2> [command3...] <outfile>
```

<a id="readme-usage" name="readme-usage"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* USAGE
------------------------------ -->
## ⚡️ Usage

**With file as input:**

```console
$ ./pipex a.txt "head -n5" "cat --number" "grep error" b.txt
$ cat b.txt
     1  An error has occurred!
     4  An error has occurred!
```

<br>

**With heredoc-style input:**

```console
$ ./pipex here_doc DEL "head -n5" "cat --number" "grep error" b.txt
here_doc > An error has occurred!
here_doc > Random line.
here_doc > Random line.
here_doc > An error has occurred!
here_doc > Random line.
here_doc > An error has occurred!
here_doc > DEL
$ cat b.txt
     1  An error has occurred!
     4  An error has occurred!
```

<a id="readme-makefile" name="readme-makefile"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* MAKEFILE
------------------------------ -->
## 🛠️ Makefile

<table>
    <tr>
        <th align="left" width="500px">Rule</th>
        <th align="left" width="9500px">Action</th>
        </tr>
    <tr><td><code>all</code></td><td>Compile.</td></tr>
    <tr><td><code>clean</code></td><td>Delete all generated object files</td></tr>
    <tr><td><code>fclean</code></td><td>Apply <code>clean</code>, <code>lclean</code>and delete the executable.</td></tr>
    <tr><td><code>lclean</code></td><td>Apply <code>fclean</code> to all used libraries.</td></tr>
    <tr><td><code>re</code></td><td>Apply <code>fclean</code> and force recompile.</td></tr>
</table>

[**⛓️ FILE : MAKEFILE**](Makefile)

<a id="readme-license" name="readme-license"></a>
<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>

<!-- ------------------------------
* LICENSE
------------------------------ -->
## 📄 License

This project is licensed under the terms of the **MIT** license.

[**⛓️ FILE : LICENSE**](LICENSE.md)

<p align="right"><b><a href="#readme-top">TOP ⬆️</a></b></p>
