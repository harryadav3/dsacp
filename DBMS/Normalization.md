# Normalization in Databases

Normalization is a process in database design to organize data to reduce redundancy and improve data integrity. The main goal of normalization is to divide large tables into smaller ones and link them using relationships to minimize duplication and ensure data dependencies make sense.

## Basic Concept

Think of normalization like organizing your files in a filing cabinet. Instead of having a big folder with all your documents mixed up, you create separate folders for different types of documents. This makes it easier to find, update, and manage your documents.

## Types of Normalization

There are several normal forms, each with specific rules to achieve a higher level of normalization. Here are the most commonly used normal forms:

1. **First Normal Form (1NF)**
2. **Second Normal Form (2NF)**
3. **Third Normal Form (3NF)**
4. **Boyce-Codd Normal Form (BCNF)**

### First Normal Form (1NF)

**Goal**: Ensure that each column contains only atomic (indivisible) values and each column contains values of a single type.

**Analogy**: Imagine you have a phone book. Instead of writing multiple phone numbers in one entry, you create separate entries for each phone number.

**Example**:

| StudentID | Name  | Phone Numbers      |
|-----------|-------|--------------------|
| 1         | Alice | 123-4567, 234-5678 |
| 2         | Bob   | 345-6789           |

After applying 1NF:

| StudentID | Name  | Phone Number |
|-----------|-------|--------------|
| 1         | Alice | 123-4567     |
| 1         | Alice | 234-5678     |
| 2         | Bob   | 345-6789     |

### Second Normal Form (2NF)

**Goal**: Ensure that the table is in 1NF and all non-key attributes are fully dependent on the primary key.

**Note**: Partial dependencies (where a non-key attribute is dependent on part of a composite primary key) should be eliminated.

**Analogy**: If you're organizing a library, instead of having books scattered across different sections without any clear categorization, you ensure each book is placed in a specific section and fully categorized.

**Example**:

Consider a table with a composite primary key (StudentID, CourseID):

| StudentID | CourseID | StudentName | CourseName |
|-----------|----------|-------------|------------|
| 1         | 101      | Alice       | Math       |
| 1         | 102      | Alice       | English    |
| 2         | 101      | Bob         | Math       |

After applying 2NF:

**Student Table**:

| StudentID | StudentName |
|-----------|-------------|
| 1         | Alice       |
| 2         | Bob         |

**Course Table**:

| CourseID | CourseName |
|----------|------------|
| 101      | Math       |
| 102      | English    |

**Enrollment Table**:

| StudentID | CourseID |
|-----------|----------|
| 1         | 101      |
| 1         | 102      |
| 2         | 101      |

### Third Normal Form (3NF)

**Goal**: Ensure that the table is in 2NF and all non-key attributes are not only fully dependent on the primary key but also non-transitively dependent on it.

**Note**: Transitive dependencies (where a non-key attribute depends on another non-key attribute) should be eliminated.

**Analogy**: Think of a recipe book. Instead of listing ingredients with their quantities and units repeatedly, you list ingredients once and reference them.

**Example**:

Consider the following table:

| StudentID | StudentName | CourseID | CourseName | InstructorName |
|-----------|-------------|----------|------------|----------------|
| 1         | Alice       | 101      | Math       | Mr. Smith      |
| 1         | Alice       | 102      | English    | Mrs. Brown     |
| 2         | Bob         | 101      | Math       | Mr. Smith      |

After applying 3NF:

**Student Table**:

| StudentID | StudentName |
|-----------|-------------|
| 1         | Alice       |
| 2         | Bob         |

**Course Table**:

| CourseID | CourseName | InstructorName |
|----------|------------|----------------|
| 101      | Math       | Mr. Smith      |
| 102      | English    | Mrs. Brown     |

**Enrollment Table**:

| StudentID | CourseID |
|-----------|----------|
| 1         | 101      |
| 1         | 102      |
| 2         | 101      |

### Boyce-Codd Normal Form (BCNF)

**Goal**: A stronger version of 3NF where every determinant must be a candidate key.

**Analogy**: In a team project, every team leader (determinant) should have a unique responsibility (candidate key), ensuring no overlap and clear authority.

**Example**:

Consider the following table:

| CourseID | Instructor | Time    |
|----------|------------|---------|
| 101      | Mr. Smith  | 9:00 AM |
| 102      | Mrs. Brown | 10:00 AM|
| 101      | Mrs. Brown | 11:00 AM|

In this case, `Instructor` is not a candidate key, but it determines `Time`. To satisfy BCNF, we need to decompose the table further to ensure all determinants are candidate keys.

After applying BCNF:

**Course Table**:

| CourseID | Time    |
|----------|---------|
| 101      | 9:00 AM |
| 102      | 10:00 AM|

**Instructor Table**:

| Instructor | CourseID |
|------------|----------|
| Mr. Smith  | 101      |
| Mrs. Brown | 102      |
| Mrs. Brown | 101      |

## Summary

- **1NF**: Eliminate repeating groups; ensure atomicity.
- **2NF**: Ensure full functional dependency on the primary key.
- **3NF**: Remove transitive dependencies.
- **BCNF**: Ensure every determinant is a candidate key.

Using these normalization forms helps to organize data efficiently, minimize redundancy, and maintain data integrity.
