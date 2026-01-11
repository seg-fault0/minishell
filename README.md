# 🐚 Minishell

A minimalist **Unix shell** implementation — as beautiful as a shell — part of the 42/1337 curriculum.

[![Language](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![42](https://img.shields.io/badge/School-42-black.svg)](https://42.fr)

## 📖 Description

**Minishell** is a simplified version of bash, implementing core shell functionalities from scratch. This project provides deep understanding of how shells work: process creation, command execution, file descriptors, and signal handling.

This project teaches:
- Parsing
- Process creation with `fork()`
- Program execution with `execve()`
- File descriptor manipulation
- Pipe and redirection handling
- Signal management
- Environment variable handling

## 🎯 How a Shell Works

```
┌──────────────────────────────────────────────────────────────────┐
│                         SHELL LOOP                               │
└──────────────────────────────────────────────────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    Display Prompt   │
                    │      minishell$     │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │    Read Input       │
                    │    (readline)       │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │        Parser       │
                    │  "ls -la | grep a"  │
                    │         ↓           │
                    │  [ls][-la][|][grep] │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │      Expander       │
                    │   $VAR → value      │
                    │   $? → exit status  │
                    └─────────────────────┘
                               │
                               ▼
                    ┌─────────────────────┐
                    │      Executor       │
                    │  fork() + execve()  │
                    │  Handle pipes/redir │
                    └─────────────────────┘
                               │
                               ▼
                         Loop back ↺
```

## ✨ Features

### Command Execution
| Feature | Description | Example |
|---------|-------------|---------|
| ✅ Simple commands | Execute binaries from PATH | `ls -la` |
| ✅ Absolute/Relative paths | Direct path execution | `/bin/ls`, `./script.sh` |
| ✅ Command not found | Error handling | `asdf` → `command not found` |

### Built-in Commands
| Builtin | Description | Example |
|---------|-------------|---------|
| `echo` | Print text (with `-n` flag) | `echo -n "hello"` |
| `cd` | Change directory | `cd /home`, `cd ..`, `cd ~` |
| `pwd` | Print working directory | `pwd` |
| `export` | Set environment variable | `export VAR=value` |
| `unset` | Remove environment variable | `unset VAR` |
| `env` | Print environment | `env` |
| `exit` | Exit shell with status | `exit 42` |

### Redirections
| Operator | Description | Example |
|----------|-------------|---------|
| `>` | Redirect output (overwrite) | `echo "hi" > file.txt` |
| `>>` | Redirect output (append) | `echo "hi" >> file.txt` |
| `<` | Redirect input | `cat < file.txt` |
| `<<` | Here-document | `cat << EOF` |

### Pipes
| Feature | Description | Example |
|---------|-------------|---------|
| `\|` | Pipe output to next command | `ls \| grep .c` |
| Multiple pipes | Chain commands | `cat file \| grep a \| wc -l` |

### Environment & Expansion
| Feature | Description | Example |
|---------|-------------|---------|
| `$VAR` | Variable expansion | `echo $HOME` |
| `$?` | Last exit status | `echo $?` |
| `' '` | Single quotes (literal) | `echo '$HOME'` → `$HOME` |
| `" "` | Double quotes (expand $) | `echo "$HOME"` → `/home/user` |

### Signal Handling
| Signal | Interactive Mode | Execution Mode |
|--------|-----------------|----------------|
| `Ctrl+C` | New prompt | Terminate command |
| `Ctrl+D` | Exit shell | EOF |
| `Ctrl+\` | Ignored | Quit command |

## 🛠️ Installation

### Prerequisites

- CC compiler
- Make
- Readline library

```bash
# Install readline on Debian/Ubuntu
sudo apt-get install libreadline-dev

# Install readline on macOS
brew install readline
```

### Build

```bash
# Clone the repository
git clone https://github.com/seg-fault0/minishell.git
cd minishell

# Compile
make

# Clean object files
make clean

# Full clean
make fclean

# Recompile
make re
```

## 🚀 Usage

```bash
./minishell
```

### Example Session

```bash
minishell$ echo "Hello, World!"
Hello, World!
minishell$ pwd
/home/user/minishell
minishell$ cd ..
minishell$ ls -la | grep minishell
drwxr-xr-x  8 user user  4096 Jan 10 12:00 minishell
minishell$ export MY_VAR="42 is awesome"
minishell$ echo $MY_VAR
42 is awesome
minishell$ cat << EOF
> This is a
> here document
> EOF
This is a
here document
minishell$ echo $?
0
minishell$ exit
```

## 📁 Project Structure

```
.
├── Makefile
├── includes
│   └── minishell.h
└── srcs
    ├── builtin
    │   ├── chdir.c
    │   ├── echo.c
    │   ├── env.c
    │   ├── exit.c
    │   ├── export.c
    │   ├── main.c
    │   ├── pwd.c
    │   └── unset.c
    ├── core
    │   ├── err.c
    │   ├── exit.c
    │   ├── init_ms.c
    │   ├── luncher.c
    │   ├── main.c
    │   └── reseter.c
    ├── exe
    │   ├── exe.c
    │   ├── exit_code.c
    │   ├── fd_manager.c
    │   ├── init.c
    │   ├── main.c
    │   └── wait.c
    ├── fds
    │   ├── here_doc.c
    │   ├── infd.c
    │   ├── main.c
    │   └── oufd.c
    ├── libft
    │   ├── alpha.c
    │   ├── ft_atoi.c
    │   ├── ft_itoi.c
    │   ├── ft_mem.c
    │   ├── ft_putnbr.c
    │   ├── ft_split.c
    │   ├── ft_split_len.c
    │   └── str.c
    ├── other
    │   ├── arr_utils.c
    │   ├── arr_utils2.c
    │   ├── char.c
    │   ├── checkers.c
    │   ├── checkers2.c
    │   ├── free.c
    │   ├── str.c
    │   └── utils.c
    ├── parsing
    │   ├── epand_vars_helper.c
    │   ├── expand_vars.c
    │   ├── extract_cmd.c
    │   ├── helper.c
    │   ├── heredoc_expand.c
    │   ├── main.c
    │   ├── parse_cmd.c
    │   ├── parse_infile.c
    │   ├── parse_outfile.c
    │   └── remove_files.c
    ├── signals
    │   ├── heredoc_signal.c
    │   └── ms_signals.c
    └── synthax
        ├── main.c
        ├── op_counter.c
        ├── operators.c
        ├── pipe.c
        ├── quotes.c
        └── redir.c

```

## 🔧 Technical Implementation

### Parser (Command Structure)

```c
typedef struct s_parsed
{
	char	**tmp2d;
	char	***cmd;
	char	***infiles;
	char	***oufiles;
	int		cmd_nbr;
}t_parsed;

```

### Execution Pipeline

```c
// For: cmd1 | cmd2 | cmd3
//
//  ┌──────┐    pipe1    ┌──────┐    pipe2    ┌──────┐
//  │ cmd1 │ ──────────► │ cmd2 │ ──────────► │ cmd3 │
//  └──────┘   [0][1]    └──────┘   [0][1]    └──────┘
//     ▲                                          │
//     │                                          ▼
//    INFD                                         OUFD

void	ft_chiled(t_ms *ms, int rfd, int *pfd)
{
	char	**tmp;

	signal(SIGINT, SIG_DFL);
	tmp = ms->cmd.cmd[ms->cmd.counter];
	if (tmp[0] == NULL)
		return (close(rfd), close_pipe(pfd), ft_exit(ms));
	fd_manager(ms, rfd, pfd);
	if (is_builtin(tmp[0]) == TRUE)
		builtin_exe(ms, tmp[0]);
	else if (ft_strchr(tmp[0], '/'))
		execve(tmp[0], tmp, ms->env);
	ms->cmd.cur_exit_code = get_exit_code(ms);
	ft_exit(ms);
}

void	ft_start(t_ms *ms, int rfd)
{
	int	pfd[2];
	int	pid;

	if (ms->cmd.counter == ms->cmd.max_counter)
		return ;
	if (pipe(pfd) == -1)
		err_msg(ERR_PIPE_F);
	pid = fork();
	if (pid == -1)
		err_msg(ERR_FORK_F);
	if (pid == 0)
		ft_chiled(ms, rfd, pfd);
	else
	{
		signal(SIGINT, SIG_IGN);
		ms->cmd.pids[ms->cmd.counter] = pid;
		ms->cmd.counter++;
		close(pfd[1]);
		ft_start(ms, pfd[0]);
		close(pfd[0]);
	}
}

void	ft_exe(t_ms *ms)
{
	char	*first_cmd;

	if (!ms->input || !*ms->input)
		return ;
	init_cmd(ms);
	first_cmd = ms->cmd.cmd[0][0];
	if (is_main_process_exe(first_cmd) == TRUE && ms->cmd.max_counter == 1)
		builtin_exe(ms, first_cmd);
	else
	{
		ft_start(ms, ms->fd.in[0]);
		ft_wait(ms);
	}
	ms->cmd.last_exit_code = ms->cmd.cur_exit_code;
}
```

## 🧪 Testing

### Basic Commands

```bash
# Simple execution
ls
ls -la
/bin/ls

# Builtins
echo hello world
echo -n "no newline"
pwd
cd /tmp && pwd
export TEST=123 && echo $TEST
env | grep TEST
unset TEST
```

### Redirections

```bash
# Output
echo "hello" > test.txt
cat test.txt
echo "world" >> test.txt
cat test.txt

# Input
cat < test.txt
wc -l < test.txt

# Here-document
cat << END
line 1
line 2
END
```

### Pipes

```bash
ls | wc -l
cat /etc/passwd | grep root | cut -d: -f1
echo "hello world" | tr ' ' '\n' | sort
```

### Quotes & Expansion

```bash
echo "Hello $USER"
echo 'Hello $USER'
echo "Exit status: $?"
echo "$HOME/test"
echo '$HOME/test'
```

## ⚠️ Error Handling

| Error | Message |
|-------|---------|
| Command not found | `minishell: cmd: command not found` |
| Permission denied | `minishell: ./file: Permission denied` |
| No such file | `minishell: file: No such file or directory` |
| Syntax error | `minishell: syntax error` |
| Too many arguments | `minishell: exit: too many arguments` |
| Numeric argument required | `minishell: exit: abc: numeric argument required` |

## 📚 Allowed Functions

| Category | Functions |
|----------|-----------|
| **Readline** | `readline`, `rl_clear_history`, `rl_on_new_line`, `rl_replace_line`, `rl_redisplay`, `add_history` |
| **Memory** | `malloc`, `free` |
| **I/O** | `printf`, `write`, `read`, `open`, `close` |
| **Process** | `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `execve`, `exit` |
| **Signals** | `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill` |
| **File** | `access`, `stat`, `lstat`, `fstat`, `unlink`, `opendir`, `readdir`, `closedir` |
| **Descriptors** | `dup`, `dup2`, `pipe` |
| **Directory** | `getcwd`, `chdir` |
| **Environment** | `getenv` |
| **Terminal** | `isatty`, `ttyname`, `ttyslot`, `ioctl`, `tcsetattr`, `tcgetattr` |
| **Error** | `strerror`, `perror` |
| **Termcap** | `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs` |

## 📖 Resources

- [Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
- [Writing Your Own Shell](https://www.cs.purdue.edu/homes/grr/SystemsProgrammingBook/Book/Chapter5-WritingYourOwnShell.pdf)
- [Shell Command Language - POSIX](https://pubs.opengroup.org/onlinepubs/9699919799/utilities/V3_chap02.html)

## 👥 Team

| Contributor | GitHub |
|-------------|--------|
| **seg-fault0** | [@seg-fault0](https://github.com/seg-fault0) |
| **Zouhair Grir** | [@GrirZouhair](https://github.com/GrirZouhair) |

## 📄 License

This project is part of the 42 school curriculum.

---
