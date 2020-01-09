#include <gtk/gtk.h>
#include "callback.h"

//视图

student_info *p_stuinfo_head = NULL;

void cb_create_entry_addstu(GtkWidget *p_widget, gpointer data);   //添加学生信息
void cb_create_entry_findstu(GtkWidget *p_widget, gpointer data);  //查询学生信息
void cb_create_entry_delstu(GtkWidget *p_widget, gpointer data);   //删除学生信息
void cb_create_entry_printstu(GtkWidget *p_widget, gpointer data); //导出学生信息
void create_window(int argc, char **argv);                         //主菜单

int main(int argc, char **argv)
{
  p_stuinfo_head = init_student_info();
  create_window(argc, argv); //绘制主菜单
  gtk_main();
  return 0;
}

void create_window(int argc, char **argv) //主菜单
{
  GtkWidget *p_window = NULL;
  GtkWidget *p_main_box = NULL; //用于放置文本和按钮
  GtkWidget *p_button[5];       //四个按钮，每个按钮对应一个功能
  GtkWidget *p_label;           //放置顶部的文本

  gtk_init(&argc, &argv);
  p_label = gtk_label_new("请选择一项（操作结果均在终端输出）");
  //新建一个窗口
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "主菜单");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200); //设置窗口大小
  p_main_box = gtk_box_new(TRUE, 0);
  gtk_box_pack_start(GTK_BOX(p_main_box), p_label, TRUE, FALSE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_main_box);
  p_button[0] = gtk_button_new_with_label("添加学生信息"); //按钮上的文字
  p_button[1] = gtk_button_new_with_label("查询学生信息");
  p_button[2] = gtk_button_new_with_label("删除学生信息");
  p_button[3] = gtk_button_new_with_label("导出学生信息");
  g_signal_connect(G_OBJECT(p_button[0]), "clicked",
                   G_CALLBACK(cb_create_entry_addstu), NULL); //点击后调用指定函数
  g_signal_connect(G_OBJECT(p_button[1]), "clicked",
                   G_CALLBACK(cb_create_entry_findstu), NULL);
  g_signal_connect(G_OBJECT(p_button[2]), "clicked",
                   G_CALLBACK(cb_create_entry_delstu), NULL);
  g_signal_connect(G_OBJECT(p_button[3]), "clicked",
                   G_CALLBACK(cb_create_entry_printstu), NULL);

  for (int i = 0; i < 4; i++)
  {
    gtk_box_pack_start(GTK_BOX(p_main_box), p_button[i], FALSE, FALSE, 0);
  }
  gtk_widget_show_all(p_window);
}

void cb_create_entry_addstu(GtkWidget *p_widget, gpointer data) //添加学生信息
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry; //输入框
  GtkWidget *p_button;
  GtkWidget *p_label[5];
  p_label[0] = gtk_label_new("请输入学生的学号");
  p_label[1] = gtk_label_new("请输入学生的姓名");
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "添加学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_label[0], TRUE, FALSE, 0);
  p_entry_set.p_entry1 = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry_set.p_entry1, TRUE, FALSE, 0);
  p_entry_set.p_entry2 = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(p_v_box), p_label[1], TRUE, FALSE, 0);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry_set.p_entry2, TRUE, FALSE, 0);
  p_button = gtk_button_new_with_label("添加");
  g_signal_connect(G_OBJECT(p_button), "clicked",
                   G_CALLBACK(add_student_info_get_info), &p_entry_set); //将 p_entry_set 中的两个参数一起传到回调函数
  gtk_box_pack_start(GTK_BOX(p_v_box), p_button, FALSE, FALSE, 0);
  gtk_widget_show_all(p_window);
}

void cb_create_entry_findstu(GtkWidget *p_widget, gpointer data) //查询学生信息
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry;
  GtkWidget *p_button;
  GtkWidget *p_label;
  p_label = gtk_label_new("请输入学生的学号或姓名");
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "查询学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  p_entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(p_v_box), p_label, TRUE, FALSE, 0);
  p_button = gtk_button_new_with_label("查询");
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry, TRUE, FALSE, 0);
  g_signal_connect(G_OBJECT(p_button), "clicked",
                   G_CALLBACK(find_student_info_get_info), p_entry);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_button, FALSE, FALSE, 0);
  gtk_widget_show_all(p_window);
}

void cb_create_entry_delstu(GtkWidget *p_widget, gpointer data) //删除学生信息
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry;
  GtkWidget *p_button;
  GtkWidget *p_label;
  p_label = gtk_label_new("请输入学生的学号或姓名");
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "删除学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  p_entry = gtk_entry_new();
  gtk_box_pack_start(GTK_BOX(p_v_box), p_label, TRUE, FALSE, 0);
  p_button = gtk_button_new_with_label("删除");
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry, TRUE, FALSE, 0);
  g_signal_connect(G_OBJECT(p_button), "clicked",
                   G_CALLBACK(delete_student_info_get_info), p_entry);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_button, FALSE, FALSE, 0);
  gtk_widget_show_all(p_window);
}

void cb_create_entry_printstu(GtkWidget *p_widget, gpointer data) //导出学生信息
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry;
  GtkWidget *p_button;
  GtkWidget *p_label;
  p_label = gtk_label_new("已经导出到 data.out");
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "导出学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_label, TRUE, FALSE, 0);
  gtk_widget_show_all(p_window);
  print_student_info();
}
