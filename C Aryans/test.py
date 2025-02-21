import tkinter as tk
from tkinter import messagebox, simpledialog
import json
import os

class ToDoListApp:
    def __init__(self, root):
        self.root = root
        self.root.title("To-Do List App")
        
        self.tasks = self.load_tasks()
        
        self.task_listbox = tk.Listbox(root, width=50, height=15)
        self.task_listbox.pack(pady=20)

        self.add_button = tk.Button(root, text="Add Task", command=self.add_task)
        self.add_button.pack(pady=5)

        self.remove_button = tk.Button(root, text="Remove Task", command=self.remove_task)
        self.remove_button.pack(pady=5)

        self.view_button = tk.Button(root, text="View Tasks", command=self.view_tasks)
        self.view_button.pack(pady=5)

        self.populate_tasks()

    def load_tasks(self, filename='tasks.json'):
        if os.path.exists(filename):
            with open(filename, 'r') as file:
                return json.load(file)
        return []

    def save_tasks(self, filename='tasks.json'):
        with open(filename, 'w') as file:
            json.dump(self.tasks, file, indent=4)

    def add_task(self):
        task = simpledialog.askstring("Add Task", "Enter the task:")
        if task:
            self.tasks.append(task)
            self.save_tasks()
            self.populate_tasks()
            messagebox.showinfo("Success", f'Task added: "{task}"')

    def remove_task(self):
        try:
            selected_task_index = self.task_listbox.curselection()[0]
            task = self.tasks[selected_task_index]
            del self.tasks[selected_task_index]
            self.save_tasks()
            self.populate_tasks()
            messagebox.showinfo("Success", f'Task removed: "{task}"')
        except IndexError:
            messagebox.showwarning("Warning", "Please select a task to remove.")

    def view_tasks(self):
        self.populate_tasks()

    def populate_tasks(self):
        self.task_listbox.delete(0, tk.END)
        for task in self.tasks:
            self.task_listbox.insert(tk.END, task)

if __name__ == "__main__":
    root = tk.Tk()
    app = ToDoListApp(root)
    root.mainloop()
