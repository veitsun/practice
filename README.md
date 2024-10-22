# 小菜鸡必读
![alt text](./image/conflict.png)

### 如何编译链接整个项目

- 第一次编译链接(后面所有的命令都是在项目根目录下执行的)
  - ```make play```
- 之后每次编译链接
  - ```make replay```
- clear编译链接出来的build文件夹 
  - ```make clean```
  
### 执行代码（请在自己对应的项目根目录下的xx.cpp下面写具体应用）

- 运行代码（编译链接之后）
  - ```make 姓名``` (示例 ： make sunwei)

### 提交代码请提交到远程仓库的main分支(自己```git fetch origin```检查是否有conflicts)

##### git 在push之前如何检查是否有冲突


在执行 git push 之前检查冲突的最佳做法通常是先尝试拉取 (git pull) 最新的更改，这样可以确保你的本地副本是最新的，并且可以提前发现并解决任何可能的冲突。

以下是检查冲突的一些步骤：

- 拉取最新更改:
  - 使用 git fetch 命令从远程仓库获取最新的提交，但不自动合并到当前分支。这可以帮助你了解远程分支上的最新状态。
    - ```git fetch origin```
  - 使用 git pull 命令拉取最新的更改并尝试与你的本地更改合并。如果存在冲突，Git 会在这里提示你。
    - ```git pull origin <your_branch>```

- 查看状态:
  - 如果你担心冲突，可以先用 git status 查看工作目录的状态，确认是否有未暂存或未提交的更改。
    - ```git status```

- 使用 git diff 检查差异:
  - 如果你想检查本地分支和远程分支之间的差异，可以使用 git diff 命令加上远程分支的引用。
    - ```git diff <your_branch> origin/<your_branch>```

- 解决冲突:
  - 如果 ```git pull``` 显示有冲突，你需要手动解决这些冲突。打开标记为冲突的文件，查找冲突标记（```<<<<<<<, =======, >>>>>>>```），并决定保留哪一部分更改，然后删除这些标记。

通过上述步骤，你可以在 git push 之前确保你的提交不会与远程仓库中的其他提交发生冲突。如果确实发现了冲突，你应该先解决它们再继续推送。



