# Employee Management System

### Overview
This project is a **modular Employee Management System** built in **C language**.  
The project is divided into multiple phases and modules so that each team member can work independently.

It uses **binary file handling (.dat)** for faster and more secure data storage.



## Project Phases

### **Phase 1**
**Objective:** Foundation  
**Tasks:**
- Create the main menu.  
- Add a password-protected login system.  
- Display the dashboard after successful login.  
- Define the structure of an Employee.

---

### **Phase 2**
**Objective:** Implement employee management features.  
**Functions to Implement:**
- `addEmployee()`
- `removeEmployee()`
- `searchEmployee()`
- `listEmployees()`

**Storage:** `employees.dat`

---

### **Phase 3**
**Objective:** Develop the Performance Tab.  
**Formula:**  
Performance = JobsCompleted / HoursWorked

Display performance in a formatted, aligned table.

---

### **Phase 4**
**Objective:** Applications Menu
**Functions:**
- Add new applicants.  
- Remove an application.  

**Storage:** `applications.dat`

---

### **Phase 5**
**Objective:** Finalize interface.  
**Tasks:**
- Align menu items neatly.  
- Improve formatting.  
- Add final touches.

---

### **Phase 6 (Optional)**
**Objective:** Add advanced features (if completed before 18 Nov).  
**Possible Additions:**
- Pending Jobs.  
- Assign Jobs to employees.  
- Other features.

---

## 🗂️ Directory Structure

EmployeeManagementSystem/
│
├── include/            # Header files
│ ├── login.h
│ ├── employee.h
│ ├── jobs.h
│ ├── applications.h
│ └── extras.h
│
├── app/                # Implementation files
│ ├── main.c
│ ├── login.c
│ ├── employee.c
│ ├── jobs.c
│ ├── applications.c
│ └── extras.c
│
├── data/               # Persistent storage
│ ├── employees.dat
│ ├── applications.dat
│ └── login.dat
│
└── helper/             # Developer documentation
  ├── login.txt
  ├── employee.txt
  ├── jobs.txt
  ├── applications.txt
  └── extras.txt


  
---

## Modular Development Rules

1. **Each module** has its own `.h` (header) and `.c` (implementation) file.  
   - Header ==> declarations only.  
   - C file ==> actual function definitions.  

2. **Each team member must document** their work inside the `helper/` folder.  
   - Example: `helper/login_notes.txt`  
   - Include:
     - Functions added
     - Dependencies
     - File handling info
     - Compilation notes

3. **.dat files**
   - Use **binary mode** (`rb`, `wb`, `ab`, etc.)
   - Example:
     ```c
     fwrite(&emp, sizeof(struct Employee), 1, fp);
     fread(&emp, sizeof(struct Employee), 1, fp);
     ```
   - Data persists even after program closes.

4. **Testing & Integration**
   - Test each module individually before integration.
   - Include its header in `main.c` after testing.

---

### EXAMPLE WORKFLOW

If someone is working on login.c:

 1. Create helper/login.txt

 2. Add function declarations in include/login.h

 3. Write function definitions in app/login.c

 4. Use data/login.dat for data storage and retrieval

 5. Test independently before merging

 6. Mark completion in login.txt