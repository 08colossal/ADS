DROP TABLE Employees;
DROP TABLE Departments;
CREATE TABLE Departments(
	department_id SERIAL PRIMARY KEY,
	department_name VARCHAR(30),
	department_description VARCHAR(50)
);

CREATE TABLE Employees(
	employee_id INTEGER NOT NULL PRIMARY KEY,
	department_id INT REFERENCES Departments(department_id),
	employee_name VARCHAR(100) NOT NULL,
	employee_cpf CHAR(11),
	employee_birth DATE
);

CREATE TABLE Department_Employees(
	department_id INT NOT NULL REFERENCES Departments(department_id),
	employee_id INT NOT NULL REFERENCES Employees(employee_id),
	PRIMARY KEY (department_id, employee_id)
);