import tkinter as tk

def agregar(valor):
    entrada.insert(tk.END, valor)

def limpiar():
    entrada.delete(0, tk.END)

def calcular():
    try:
        resultado = eval(entrada.get())
        entrada.delete(0, tk.END)
        entrada.insert(0, resultado)
    except:
        entrada.delete(0, tk.END)
        entrada.insert(0, "Error")

root = tk.Tk()
root.title("Calculadora")
root.geometry("300x400")

entrada = tk.Entry(root, font=("Arial", 20), justify="right")
entrada.pack(fill="both", padx=10, pady=10)

frame = tk.Frame(root)
frame.pack()

botones = [
    "7","8","9","/",
    "4","5","6","*",
    "1","2","3","-",
    "0",".","=","+"
]

fila = 0
col = 0
for b in botones:
    if b == "=":
        btn = tk.Button(frame, text=b, width=5, height=2, command=calcular)
    else:
        btn = tk.Button(frame, text=b, width=5, height=2, command=lambda x=b: agregar(x))

    btn.grid(row=fila, column=col, padx=5, pady=5)

    col += 1
    if col > 3:
        col = 0
        fila += 1

btn_limpiar = tk.Button(root, text="Limpiar", width=10, height=2, command=limpiar)
btn_limpiar.pack(pady=10)

root.mainloop()
