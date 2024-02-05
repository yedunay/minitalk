# minitalk

## Overview

`minitalk` is a small communication project in the C programming language. It involves creating a client-server architecture for interprocess communication using signals. This README provides essential information to understand, implement, and use the `minitalk` project.

## Project Structure

The project consists of two main programs:
- **Server**: Listens for messages from clients.
- **Client**: Sends messages to the server.

## Compilation

Compile both the server and client programs using the provided Makefile:

```bash
make
```

This will generate the `server` and `client` executables.

## Usage

1. Start the server:

```bash
./server
```

The server will display its process ID (PID).

2. In a separate terminal, start the client:

```bash
./client [server_pid] [message]
```

Replace `[server_pid]` with the server's process ID and `[message]` with the message you want to send.

## Example

Start the server:

```bash
./server
```

In another terminal, send a message from the client:

```bash
./client [server_pid] "Hello, minitalk!"
```

The server will receive and display the message.

## Implementation Details

- The communication is achieved using signals, specifically `SIGUSR1` and `SIGUSR2`.
- The server waits for signals, converts them into ASCII characters, and displays the received message.
- The client sends the message bit by bit using the server's process ID.

## Error Handling

- Ensure the server is running before starting the client.
- Verify that the server's process ID is correctly provided to the client.

## Contributions

Contributions to enhance the functionality, performance, or documentation of `minitalk` are welcome. Feel free to submit issues or pull requests.
