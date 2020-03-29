"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
" vim配置文件，将本vimrc文件拷贝到~/.vim/目录下并改名为.vimrc即可生效，文件名或
" 文件夹名前面的.代表是隐藏文件，使用ls -a命令才可以看见，~是家目录
" cp vimrc ~/.vim/.vimrc
" 然后重新登出登入电脑生效
"
" vim是一款文本编辑器，在板子的嵌入式操作系统中只能使用它来编辑文件(因为
" 系统没有图形界面编辑器)，使用方式是vi 文件名，或者vim 文件名
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

" ts是tabstop的缩写，设TAB宽显示为4个空格，Linux默认显示为8个空格
" expandtab是输入tab键时自动替换为4个空格
" 编辑Makefile前，或者编写Linux驱动前先将下面两行用:冒号注释掉，
" 因为Makefile中的命令必须以tab缩进，否则会报错；而Linux内核编码推荐空格缩进
set ts=4
set expandtab

