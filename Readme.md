<!-- ABOUT THE PROJECT -->
# About The Project

My Leetcode Project

## Prerequisites

* cmake

* clang++

* Leetcode 插件

<!-- USAGE EXAMPLES -->
## Usage

魔改VScode的Leetcode插件，让其在Solution下生成${id}.hpp 文件，并包含所需头文件和测试函数，同时修改main.cpp对${id}.hpp的引用

vscode插件地址：在用户目录下的`.vscode/extensions/*`中

具体逻辑在`showProblem`函数中, 只需要拿到题目的id即可

<!-- LICENSE -->
## License

Distributed under the MIT License. See `LICENSE.txt` for more information.
