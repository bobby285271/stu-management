# 学生管理系统（简易版）- C 语言大作业

写这个项目的主要目的，一个是应付（划掉）1 月 10 号就要截止 C 语言大作业，另一个是想借此入坑 GTK。

> 为什么是 GTK 而不是 Qt：其实仅仅是因为我目前装了个 GNOME 桌面（逃）。

## 主要功能及实现的基本原理

* 添加学生信息：用头插法将学生信息作为一个新的结点添加到链表中。
* 查询学生信息：遍历链表，匹配结点信息，匹配则打印结点信息。
* 删除学生信息：遍历链表，匹配结点信息，匹配则删除相关的结点。
* 导出学生信息：遍历链表，输出所有结点信息。

## 主要文件及函数

* `main.c`：视图文件。
  * `void cb_create_entry_addstu(GtkWidget *p_widget, gpointer data);`：添加学生信息（视图）
  * `void cb_create_entry_findstu(GtkWidget *p_widget, gpointer data);`：查询学生信息（视图）
  * `void cb_create_entry_delstu(GtkWidget *p_widget, gpointer data);`：删除学生信息（视图）
  * `void cb_create_entry_printstu(GtkWidget *p_widget, gpointer data);`：导出学生信息（视图）
  * `void create_window(int argc, char **argv);`：主菜单（视图）
* `callback.c`：后台文件。
  * `student_info *init_student_info();`：初始化（链表操作）
  * `void add_student_info(char *add_student_info_id, char *add_student_info_name);`：添加学生信息（链表操作）
  * `void find_student_info(char *p_find_student_info);`：查询学生信息（链表操作）
  * `void delete_student_info(char *p_find_student_info);`：删除学生信息（链表操作）
  * `void print_student_info();`：导出学生信息（链表操作）
  * `void add_student_info_get_info(GtkWidget *widget, gpointer data);`：添加学生信息（处理用户输入）
  * `void find_student_info_get_info(GtkWidget *widget, gpointer data);`：查询学生信息（处理用户输入）
  * `void delete_student_info_get_info(GtkWidget *widget, gpointer data);`：删除学生信息（处理用户输入）

## 编译与运行

在装有 GTK 3 的 Linux 发行版下只需这样操作：

```sh
$ gcc main.c `pkg-config --cflags --libs gtk+-3.0` && ./a.out
```

## 截图

[\[1\]](https://bobby285271.coding.net/p/img/d/img/git/raw/master/c-hw/func1.png)
[\[2\]](https://bobby285271.coding.net/p/img/d/img/git/raw/master/c-hw/func2.png)
[\[3\]](https://bobby285271.coding.net/p/img/d/img/git/raw/master/c-hw/func3.png)
[\[4\]](https://bobby285271.coding.net/p/img/d/img/git/raw/master/c-hw/func4.png)
