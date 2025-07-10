# Minishell 

A minimalist Unix shell implementation as part of the 42 School curriculum.


## 📖 Table of Contents
- [Introduction](#-introduction)
- [Features](#-features)
- [Installation & Usage](#-installation--usage)
- [Team](#-team)

## 🌟 Introduction

Minishell is a small project where we created a basic version of a Unix shell, like `bash`. It lets you run commands, use built-in commands, work with environment variables, and handle things like pipes and redirections. We also made sure it reacts properly to keyboard shortcuts like `Ctrl+C` and `Ctrl+\`. This project helped us learn how a shell works by using system functions to create new processes, run programs, and manage input and output. It was a great way to practice low-level programming and understand how command-line tools work behind the scenes.


Shoutout to my awesome teammate [@GrirZouhair](https://github.com/GrirZouhair) for the collaboration! 👏

## 🚀 Features

### Implemented
- Command execution with PATH resolution
- Builtins (`echo`, `cd`, `pwd`, `export`, `unset`, `env`, `exit`)
- Redirections (`>`, `>>`, `<`, `<<`)
- Pipes (`|`)
- Environment variables
- Signal handling (Ctrl-C, Ctrl-D, Ctrl-\)

## 💻 Installation and usage

```bash
git clone https://github.com/seg-fault0/minishell
cd minishell
make
./minishell
```

## 👥 Team

[@seg-fault0](https://github.com/seg-fault0)

[@GrirZouhair](https://github.com/GrirZouhair)