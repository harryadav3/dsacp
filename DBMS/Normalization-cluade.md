
# Database Normalization

Normalization is a technique used in database design to organize data efficiently, reduce redundancy, and improve data integrity.

## Key Terms

1. **Prime Attribute**: An attribute that is part of any candidate key in the relation.
2. **Non-Prime Attribute**: An attribute that is not part of any candidate key in the relation.
3. **Partial Dependency**: A functional dependency where a non-prime attribute depends on only a part of a composite key.
4. **Transitive Dependency**: A functional dependency where a non-prime attribute depends on another non-prime attribute.
5. **Functional Depedency**: Functional Dependency is a realationship between two attributes in a relation where teh value fo one attribue uniquely determines the vlaue of another attribute.


Here's the explanation of functional dependency written in markdown format:

# Functional Dependency

Functional dependency is a relationship between two attributes in a relation, where the value of one attribute uniquely determines the value of another attribute.

## Definition

If A and B are attributes of a relation, B is functionally dependent on A (denoted as A → B) if each value of A is associated with exactly one value of B.

## Key Characteristics

1. For any two tuples t1 and t2 in the relation, if t1[A] = t2[A], then t1[B] = t2[B].
2. A is called the determinant, and B is the dependent.

## Examples

1. In a relation about employees:
   `Employee_ID → Employee_Name`
   (Each Employee_ID uniquely determines an Employee_Name)

2. In a relation about orders:
   `Order_ID → Order_Date`
   (Each Order_ID uniquely determines an Order_Date)

## Types of Functional Dependencies

1. **Full Functional Dependency**: When B is fully functionally dependent on A, and removing any attribute from A means the dependency doesn't hold anymore.

2. **Partial Functional Dependency**: When B is functionally dependent on a proper subset of A. This occurs with composite keys.

3. **Transitive Functional Dependency**: When A → B and B → C, then A → C is a transitive dependency.

## Importance in Normalization

1. Identifying functional dependencies is crucial for achieving higher normal forms.
2. They help in eliminating data redundancy and improving data integrity.
3. Understanding functional dependencies aids in proper database design and optimization.

## Example Scenario

Consider a table:

| Student_ID | Course_ID | Course_Name | Instructor |
|------------|-----------|-------------|------------|
| 1          | CS101     | Programming | Dr. Smith  |
| 2          | CS101     | Programming | Dr. Smith  |
| 1          | MATH201   | Calculus    | Dr. Jones  |

Functional dependencies:
- {Student_ID, Course_ID} → {Course_Name, Instructor}
- Course_ID → Course_Name
- Course_ID → Instructor

Here, we can see both full and partial functional dependencies, which would be addressed through normalization.


***** 


### 1. First Normal Form (1NF)

**Definition:** Each column contains atomic (indivisible) values, and there are no repeating groups.

**Analogy:** Think of a well-organized closet where each item has its own specific place.

**Example:**
```
Before 1NF:
| Student | Courses           |
|---------|-------------------|
| Alice   | Math, Science, Art|

After 1NF:
| Student | Course  |
|---------|---------|
| Alice   | Math    |
| Alice   | Science |
| Alice   | Art     |
```

**Dependency:** Partial dependency may exist in 1NF.

### 2. Second Normal Form (2NF)

**Definition:** Meets 1NF requirements and all non-prime attributes are fully functionally dependent on the primary key.

**Analogy:** A recipe book where each recipe is uniquely identified by its name, and all ingredients directly relate to that specific recipe.

**Example:**
```
Before 2NF:
| Order_ID | Product | Category | Quantity |
|----------|---------|----------|----------|
| 1        | Apple   | Fruit    | 5        |

After 2NF:
Table 1: Orders
| Order_ID | Product | Quantity |
|----------|---------|----------|
| 1        | Apple   | 5        |

Table 2: Products
| Product | Category |
|---------|----------|
| Apple   | Fruit    |
```

**Dependency:** Partial dependency is eliminated in 2NF.

### 3. Third Normal Form (3NF)

**Definition:** Meets 2NF requirements and has no transitive dependencies.

**Analogy:** A library where books are organized by genre, then author, then title - each classification depends only on the previous one.

**Example:**
```
Before 3NF:
| Employee_ID | Department | Department_Head |
|-------------|------------|-----------------|
| 1           | Sales      | John Doe        |

After 3NF:
Table 1: Employees
| Employee_ID | Department |
|-------------|------------|
| 1           | Sales      |

Table 2: Departments
| Department | Department_Head |
|------------|-----------------|
| Sales      | John Doe        |
```

**Dependency:** Transitive dependencies are eliminated in 3NF.

### 4. Boyce-Codd Normal Form (BCNF)

**Definition:** A stricter version of 3NF, where every determinant must be a candidate key.

**Analogy:** A perfectly organized toolbox where each tool has a unique place, and no tool's location depends on another tool's location.

**Example:**
```
Before BCNF:
| Student | Course | Professor |
|---------|--------|-----------|
| Alice   | Math   | Smith     |

After BCNF:
Table 1: Student_Course
| Student | Course |
|---------|--------|
| Alice   | Math   |

Table 2: Course_Professor
| Course | Professor |
|--------|-----------|
| Math   | Smith     |
```

**Dependency:** All functional dependencies are on the primary key.

## Additional Points

1. Primary keys should not have partial or transitive dependencies.
2. Prime attributes are used to uniquely identify records and are typically part of the primary key.
3. Non-prime attributes provide additional information but are not used for unique identification.
4. Partial dependencies occur when a non-prime attribute depends on only part of a composite key, which is addressed in 2NF.
5. Transitive dependencies occur when a non-prime attribute depends on another non-prime attribute, which is addressed in 3NF.
6. Higher normal forms (4NF, 5NF) exist but are less commonly used in practice.
7. Normalization helps prevent update anomalies and ensures data consistency.
8. Sometimes, denormalization is used for performance reasons in specific scenarios.

Would you like me to elaborate on any specific part of this explanation or provide more examples for the new terms?