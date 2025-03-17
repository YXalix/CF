<!-- ABOUT THE PROJECT -->
# About The Project

My Leetcode C++ Solution, 一个用于存放Leetcode题解的仓库，并且自动化生成leetcode题目可执行与Debug环境。

## 前置条件

- `VScode`
- `Leetcode`插件
- `C++`编译环境 (llvm)
- `CMake`
- `clangd`

## 使用指南

### 获取本仓库

```bash
git clone https://github.com/YXalix/CF.git
```

### 安装`Leetcode`插件

vscode插件商店搜索`Leetcode`，安装后配置`leetcode.workspaceFolder`为本仓库的`Solutions`目录。

### 修改`Leetcode`插件

下载好的vscode插件地址：在用户目录下的`.vscode/extensions/*`中

将原`showProblem`替换成下面的`showProblem`函数

```javascript
showProblem(problemNode, language, filePath, showDescriptionInComment = false, needTranslation) {
    return __awaiter(this, void 0, void 0, function* () {
        const templateType = showDescriptionInComment ? "-cx" : "-c";
        const cmd = [yield this.getLeetCodeBinaryPath(), "show", problemNode.id, templateType, "-l", language];
        if (!needTranslation) {
            cmd.push("-T"); // use -T to force English version
        }
        if (!(yield fse.pathExists(filePath))) {
            yield fse.createFile(filePath);
            const codeTemplate0 = yield this.executeCommandWithProgressEx("Fetching problem data...", this.nodeExecutable, cmd);
            const codeTemplate = "#include \"utils.hpp\"\n" + codeTemplate0 + "\ninline void test(){\n\tSolution s;\n}";
            yield fse.writeFile(filePath, codeTemplate);
        }
        const parts = filePath.split('/');
        const filename = parts.pop();
        const main_path = vscode_1.workspace.getWorkspaceFolder(vscode_1.Uri.file(filePath)).uri.fsPath + "/main.cpp";
        const main_template = "#include <" + filename + ">\n" + "\nint main(){\n\ttest();\n}"
        yield fse.writeFile(main_path, main_template);
    });
}
```

## 修改思路

魔改`VScode`的`Leetcode`插件，让其在`Solutions`下生成`{id}.{slug}.{ext}`文件，并且在`{workspace}/main.cpp`中引用`{id}.{slug}.{ext}`文件。

```cpp
// in main.cpp
#include <1963.使字符串平衡的最小交换次数.cpp>

int main(){
    test();
}
```

```cpp
// in 1963.使字符串平衡的最小交换次数.cpp
#include "utils.hpp"
class Solution { };
// @lc code=end
inline void test(){
    Solution s;
    // put your test code here
}
```

在`utils.hpp`中包含了一些常用的头文件，以及一些常用的函数，如二叉树构建，`printVector`等。
