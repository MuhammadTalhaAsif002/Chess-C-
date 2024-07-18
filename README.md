# Console Chess Game

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Game Rules](#game-rules)
- [Contributing](#contributing)
- [License](#license)
- [Acknowledgements](#acknowledgements)

## Introduction
This project is a console-based chess game implemented in C++. It offers a fully functional chess game that can be played on the console. The game supports all standard chess rules and features.

## Features
- **Player vs Player Mode**: Two human players can play against each other.
- **Full Chess Rule Set**: Implements all standard chess rules including castling, en passant, and promotion.
- **Board Display**: The chessboard is displayed in the console.
- **Move Validation**: Validates all moves according to chess rules.
- **Check and Checkmate Detection**: Detects check and checkmate conditions.

## Prerequisites
- C++ Compiler (e.g., g++)
- Standard C++ Library

## Installation
1. Clone the repository to your local machine:
    ```sh
    git clone <repository-url>
    ```
2. Navigate to the project directory:
    ```sh
    cd console-chess-game
    ```
3. Compile the project using g++:
    ```sh
    g++ -o chess_game chess_game.cpp
    ```

## Usage
1. Run the compiled executable:
    ```sh
    ./chess_game
    ```
2. Follow the on-screen instructions to play the game.
3. Players take turns to make moves by entering coordinates.

### Main Functions
- `initializeBoard()`: Sets up the chessboard with the initial piece positions.
- `displayBoard()`: Displays the current state of the chessboard.
- `movePiece(int startX, int startY, int endX, int endY)`: Moves a piece from the start position to the end position.
- `validateMove(int startX, int startY, int endX, int endY)`: Validates if a move is legal according to chess rules.
- `isCheck()`: Checks if the current player is in check.
- `isCheckmate()`: Checks if the current player is in checkmate.

## Game Rules
- **Movement**: Pieces move according to standard chess rules.
- **Castling**: Allowed if neither the king nor the rook has moved and there are no pieces between them.
- **En Passant**: Can be performed immediately after an opponent's pawn moves two squares forward from its starting position.
- **Promotion**: Pawns that reach the opposite end of the board can be promoted to any other piece (except a king).

## Contributing
Contributions are welcome! Please follow these steps:
1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes and commit them (`git commit -m 'Add new feature'`).
4. Push to the branch (`git push origin feature-branch`).
5. Create a new Pull Request.

## Acknowledgements
- Thanks to the C++ community for their continuous support and resources.
- Special thanks to the contributors who helped in making this project possible.
