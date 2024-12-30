# Library Management System


### Overview
The Library Management System is a C++ application designed to manage a library’s books and students. It handles three types of books:
- **Textbooks**
- **StoryBooks**
- **General Books**

It allows users to:
- Add and modify book records.
- Manage student details, including book issue statuses.
- Display details for books and students.

### Features
1. **Book Management**:
   - **Add Books**: Add details for textbooks, storybooks, or general books.
   - **Modify Books**: Edit the details of an existing book record.
   - **Display Book Details**: Search and display the details of a specific book.

2. **Student Management**:
   - **Add Students**: Register students with their admission numbers and details.
   - **Issue Book**: Manage book-issuing status for students.
   - **Modify Student Records**: Edit student details.

3. **Persistence**:
   - Data is stored in binary files (`book.dat` and `student.dat`) for persistent storage.

### File Structure
- **book.dat**: Stores book information.
- **student.dat**: Stores student information.

### Classes
1. **`book`**:
   - Attributes:
     - `bno`: Book number
     - `bname`: Book name
     - `aname`: Author name
   - Methods:
     - `createbook`: Adds a book entry.
     - `showbook`: Displays book details.
     - `modifybook`: Edits an existing book entry.

2. **`Textbook`** (inherits `book`):
   - Additional Attributes:
     - `Academic_Level`: Level of the book (e.g., UG, PG).
     - `NoInStock`: Books available in stock.
     - `NumberOfIssues`: Issues related to the book.
   - Methods override `createbook`, `showbook`, and `modifybook`.

3. **`StoryBook`** (inherits `book`):
   - Additional Attributes:
     - `Genre`: Type of story (e.g., Drama, Adventure).
     - `Type`: Category (e.g., Novel, Biography).
     - `IsIssueAllowed`: Whether the book can be issued.
   - Methods override `createbook`, `showbook`, and `modifybook`.

4. **`student`**:
   - Attributes:
     - `admno`: Admission number.
     - `name`: Student’s name.
     - `stbno`: Book number issued by the student.
     - `token`: Token count for book issuance.
   - Methods:
     - `createstudent`: Adds a student entry.
     - `showstudent`: Displays student details.
     - `modifystudent`: Edits student records.

### Key Functions
- **`writebook()`**: Writes new book entries to `book.dat`.
- **`writestudent()`**: Writes new student entries to `student.dat`.
- **`displayspb()`**: Searches and displays book details by book number.
- **`displaysps()`**: Searches and displays student details by admission number.
- **`modifybook()`**: Modifies book details and updates `book.dat`.

### Dependencies
- **Libraries**: `<iostream>`, `<fstream>`, `<iomanip>`, `<cstring>`, `<string>`, `<conio.h>`.

### Compilation and Execution
1. Compile using g++:
   ```sh
   g++ -o library_management main.cpp
   ```
2. Run the executable:
   ```sh
   ./library_management
   ```


src/
├── main.cpp
├── book.h
├── book.cpp
├── textbook.h
├── textbook.cpp
├── storybook.h
├── storybook.cpp
├── student.h
├── student.cpp
├── file_operations.h
├── file_operations.cpp


### Error Handling
- Validates:
  - Book numbers (length: 2-6 characters).
  - Admission numbers (length: 8-10 characters).
- Uses exceptions (e.g., throws `char` codes) for invalid inputs.

### Notes
- Uses `gets` for string inputs with spaces. Replace it with `std::getline` for modern compilers.
- Adjust file paths and permissions as per your system.

---

### Author
- **Name**: Anant Bhardwaj  
- **Purpose**: Educational project to demonstrate file handling and object-oriented programming in C++.

---

