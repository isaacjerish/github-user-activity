# GitHub Activity CLI (Work in Progress)

This is a simple C++ command-line tool that fetches and displays the recent public GitHub activity of a specified user. It uses the GitHub Events API and parses the output to show the types of recent events.

## Status: Work in Progress
This project is under active development. Current features are limited to displaying event types and require enhancements such as:
- Parsing JSON properly
- Pretty printing event data
- Error handling improvements

## Requirements
- C++ compiler (e.g. `g++`)
- Internet connection
- `curl` installed on your system

##  Build
```bash
g++ -std=c++11 github-activity.cpp -o github-activity