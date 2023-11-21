import tkinter as tk

tasks = []

def show_tasks():
    task_window = tk.Tk()
    task_window.title("Danh sách công việc")
    task_window.configure(bg='lightblue')
    for i, task in enumerate(tasks, start=1):
        task_frame = tk.Frame(task_window)
        task_frame.pack(padx=10, pady=5)
        
        task_label = tk.Label(task_frame, text=f"{i}. Tiêu đề: {task['title']} - Deadline: {task['deadline']} - Trạng thái: {'Hoàn thành' if task['completed'] else 'Chưa hoàn thành'}")
        task_label.pack()

def add_task():
    add_window = tk.Tk()
    add_window.title("Thêm công việc mới")
    
    title_label = tk.Label(add_window, text="Nhập tiêu đề công việc:")
    title_label.pack(padx=10, pady=5)
    
    title_entry = tk.Entry(add_window)
    title_entry.pack(padx=10, pady=5)
    
    deadline_label = tk.Label(add_window, text="Nhập deadline (dd/mm/yyyy):")
    deadline_label.pack(padx=10, pady=5)
    
    deadline_entry = tk.Entry(add_window)
    deadline_entry.pack(padx=10, pady=5)
    
    def add():
        title = title_entry.get()
        deadline = deadline_entry.get()
        task = {'title': title, 'deadline': deadline, 'completed': False}
        tasks.append(task)
        print("Công việc được thêm vào danh sách.")
        add_window.destroy()
    
    add_button = tk.Button(add_window, text="Thêm", command=add)
    add_button.pack(padx=10, pady=5)

def mark_completed():
    mark_window = tk.Tk()
    mark_window.title("Đánh dấu công việc đã hoàn thành")
    
    for i, task in enumerate(tasks, start=1):
        task_frame = tk.Frame(mark_window)
        task_frame.pack(padx=10, pady=5)
        
        task_label = tk.Label(task_frame, text=f"{i}. Tiêu đề: {task['title']} - Deadline: {task['deadline']} - Trạng thái: {'Hoàn thành' if task['completed'] else 'Chưa hoàn thành'}")
        task_label.pack()
        
    idx_entry = tk.Entry(mark_window)
    idx_entry.pack(padx=10, pady=5)
    
    def mark():
        try:
            idx = int(idx_entry.get()) - 1
            tasks[idx]['completed'] = True
            print("Đã đánh dấu công việc là hoàn thành.")
            mark_window.destroy()
        except (ValueError, IndexError):
            print("Nhập không hợp lệ.")
    
    mark_button = tk.Button(mark_window, text="Đánh dấu", command=mark)
    mark_button.pack(padx=10, pady=5)

def clear_tasks():
    global tasks
    tasks = []
    print("Đã xóa hết danh sách công việc.")
    
def sort_by_deadline():
    global tasks
    tasks = sorted(tasks, key=lambda x: x['deadline'])
    print("Đã sắp xếp danh sách công việc theo deadline.")

root = tk.Tk()
root.title("Quản lý công việc")
root.configure(bg='lightblue')
root.geometry("500x400")

frame = tk.Frame(root, bg ='lightblue')
frame.pack(padx=10, pady=10)

show_button = tk.Button(frame, text="Hiển thị danh sách công việc", command=show_tasks, activebackground='white')
show_button.pack(padx=10, pady=5)

add_button = tk.Button(frame, text="Thêm công việc mới", command=add_task, activebackground='white')
add_button.pack(padx=10, pady=5)

mark_button = tk.Button(frame, text="Đánh dấu công việc đã hoàn thành", command=mark_completed, activebackground='white')
mark_button.pack(padx=10, pady=5)

clear_button = tk.Button(frame, text="Xóa hết danh sách công việc", command=clear_tasks, activebackground='white')
clear_button.pack(padx=10, pady=5)

sort_button = tk.Button(frame, text="Sắp xếp theo Deadline", command=sort_by_deadline, activebackground='white')
sort_button.pack(padx=10, pady=5)

root.mainloop()
