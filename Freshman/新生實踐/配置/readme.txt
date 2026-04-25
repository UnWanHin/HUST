1. 先安装 basic-miktex-21.6-x64

2. 再安装texstudio-3.1.2-win-qt5

3. 如桌面没有图标, C:\Program Files (x86)\texstudio\texstudio.exe 建桌面快捷方式

4. 打开texstudio, 再Options-->Configure TeXstudio-->Language Checking->spelling dictionary directories-->Import Dictionary 导入字典(dict-en-20190101.oxt)以便查编辑的语法拼写错误

5. 直接安装texlive.iso. 也可以安装install-tl-windows, 边下载边安装所有依赖包, 时间比较长! 

软件安装：
1. 建议装textstudio编辑, 因为标记比较明显. 但不能用它编译
2. 需要装texlive, 可以在线装(也可以在群里下载texlive.part01.rar到texlive.part42.rar解压并安装)镜像安装, 镜像有4G (https://mirrors.sustech.edu.cn/CTAN/systems/texlive/Images/texlive.iso)
编译方法:
1. 在当前文件夹的资源管理器的地址栏中输入cmd再回车
2. 输入makethesis并回车
关于插图：
1. 插图建议用visio画, 然后打印成pdf, 再用adobe pdf自带的裁剪工具裁剪, 再在文中插入该pdf文件. 则生成与插入的为矢量图效果好.