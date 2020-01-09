#include <gtk/gtk.h>
#include "callback.h"

student_info *p_stuinfo_head = NULL;

void cb_create_entry_addstu(GtkWidget *p_widget, gpointer data);  //添加学生信息
void cb_create_entry_findstu(GtkWidget *p_widget, gpointer data); //查询学生信息
void cb_create_entry_delstu(GtkWidget *p_widget, gpointer data);  //删除学生信息
int create_window(int argc, char **argv);                         //主菜单

int main(int argc, char **argv)
{
  p_stuinfo_head = init_student_info();
  create_window(argc, argv);
  gtk_main();
  return 0;
}

void cb_create_entry_addstu(GtkWidget *p_widget, gpointer data)
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry;
  GtkWidget *p_button;
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "添加学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  p_entry = gtk_entry_new();
  p_button = gtk_button_new_with_label("添加");
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry, TRUE, FALSE, 0);
  g_signal_connect(G_OBJECT(p_button), "clicked",
                   G_CALLBACK(add_student_info_get_info), p_entry);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_button, FALSE, FALSE, 0);
  gtk_widget_show_all(p_window);
}

void cb_create_entry_findstu(GtkWidget *p_widget, gpointer data)
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry;
  GtkWidget *p_button;
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "查询学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  p_entry = gtk_entry_new();
  p_button = gtk_button_new_with_label("查询");
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry, TRUE, FALSE, 0);
  g_signal_connect(G_OBJECT(p_button), "clicked",
                   G_CALLBACK(find_student_info_get_info), p_entry);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_button, FALSE, FALSE, 0);
  gtk_widget_show_all(p_window);
}

void cb_create_entry_delstu(GtkWidget *p_widget, gpointer data)
{
  gtk_button_released(p_widget);
  GtkWidget *p_window;
  GtkWidget *p_v_box;
  GtkWidget *p_entry;
  GtkWidget *p_button;
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "删除学生信息");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_v_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_v_box);
  p_entry = gtk_entry_new();
  p_button = gtk_button_new_with_label("删除");
  gtk_box_pack_start(GTK_BOX(p_v_box), p_entry, TRUE, FALSE, 0);
  g_signal_connect(G_OBJECT(p_button), "clicked",
                   G_CALLBACK(delete_student_info_get_info), p_entry);
  gtk_box_pack_start(GTK_BOX(p_v_box), p_button, FALSE, FALSE, 0);
  gtk_widget_show_all(p_window);
}

int create_window(int argc, char **argv)
{
  GtkWidget *p_window = NULL;
  GtkWidget *p_main_box = NULL;

  GtkWidget *p_button[5];

  gtk_init(&argc, &argv);

  //Create window
  p_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title(GTK_WINDOW(p_window), "主菜单");
  gtk_window_set_default_size(GTK_WINDOW(p_window), 320, 200);
  p_main_box = gtk_box_new(TRUE, 0);
  gtk_container_add(GTK_CONTAINER(p_window), p_main_box);

  p_button[0] = gtk_button_new_with_label("添加学生信息");
  p_button[1] = gtk_button_new_with_label("查询学生信息");
  p_button[2] = gtk_button_new_with_label("删除学生信息");
  p_button[3] = gtk_button_new_with_label("导出学生信息");

  g_signal_connect(G_OBJECT(p_button[0]), "clicked",
                   G_CALLBACK(cb_create_entry_addstu), NULL);
  g_signal_connect(G_OBJECT(p_button[1]), "clicked",
                   G_CALLBACK(cb_create_entry_findstu), NULL);
  g_signal_connect(G_OBJECT(p_button[2]), "clicked",
                   G_CALLBACK(cb_create_entry_delstu), NULL);
  g_signal_connect(G_OBJECT(p_button[3]), "clicked",
                   G_CALLBACK(print_student_info), NULL);

  for (int i = 0; i < 4; i++)
  {
    gtk_box_pack_start(GTK_BOX(p_main_box), p_button[i], FALSE, FALSE, 0);
  }
  gtk_widget_show_all(p_window);
}
