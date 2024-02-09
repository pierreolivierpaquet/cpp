
<div style="padding-top: 25px"></div>
<div style="text-align: center; background-color: rgba(11,11,11);border-radius: 5px;">
	<h3	style="font-family: Helvetica; font-size: 20px; color: white;padding-top: 15px;"> C++ CONVERSION TYPES </h3>
	<p style="text-align: right; padding-bottom: 5px; font-size: 10px;font-family: Helvetica; white-space: pre-wrap;"> [ ppaquet ] </p>
</div>

<!----------------------------------------------------------------------------->
### **STANDARD C CONVERSION**
---
1. <u> **IMPLICIT CONVERSION CAST.** </u>\
	The compiler automatically converts one data type to another without requiring any explicit action from the programmer.

	```c
	int		a = 42;			// Reference value.
	double	b = a;			// Implicit conversion cast

	double	d = a;			// Implicit promotion. SAFE
	int		e = d;			// Implicit demotion. RISK: bit truncation, precision loss, data loss.
	```
	* 64bits are used to store a DOUBLE / 32 bits are used to store an INT


2. <u> **EXPLICIT CONVERSION CAST.** </u>\
	This occurs when the programmer explicitly specifies a type conversion using a cast operator.
	```c
	int		a = 42;			// Reference value.
	double	c = (double)a;	// Explicit conversion
	int		f = (int)d; 	// Explicit demotion. SAFE: Same as implicit, but done voluntarily.
	```
3. <u> **REINTERPRETATION CONVERSION. </u>**\
	Conversion where the source type and the target type are the same, resulting in no actual conversion being performed. Reinterpretation typically doesn't involve modifying or reorganizing the bits in memory; instead, it involves treating the existing memory layout of an object as if it were of a different type.
	```c
	float	a	=	42.9876f;		// Reference value.

	void	*b	=	&a;				// Implicit reinterpretation cast.
	void	*c	=	(void *) &a;	// Explicit reinterpretation cast.

	void	*d	=	&a;				// Implicit promotion. SAFE
	int		*e	=	d;				// Implicit demotion. RISKY: Arbitrary cast, data loss.
	int		*f	=	(int *)d;		// Explicit demotion: SAFE: Voluntarily cast.
	```

4. <u> **TYPE QUALIFIER REINTERPRETATION** </u>
	* keyword: const
	* keyword: volatile\
	type qualifiers are used to modify the <u>**properties**</u> of variables.
	```c
	int	a = 42;	// Reference value.

	const int	*b = &a;				// Implicit type qualifier cast.
	const int	*c = (const int *)&a;	// Explicit type qualifier cast.

	const int	*d = &a;				// Implicit promotion type qualifier cast: SAFE.
	int	*e = d;							// Implicit demotion type qualifier: WILL NOT COMPILE.
	int	*f = (int *)d;					// Explicit demotion type qualifier: SAFE: done volontarily.
	```

# **NEVER USE `C` TYPE CAST IN `C++`**

(_REINTERPRETATION OF CLASS ADRESS_)
* **UPCASTING** - from DERIVED instance adress to a new BASE instance pointer.
	* Creating the derived class's pointer or reference from the base class's pointer or reference. **It means the upcasting used to convert the reference or pointer of the derived class to a base class.**

* **DOWNCASTING** - from BASE instance adress to a new DERIVED instance pointer.
	* Opposite process to the upcasting, which converts the base class's pointer or reference to the derived class's pointer or reference. **It manually cast the base class's object to the derived class's object, so we must specify the explicit typecast.**

\
[UPCASTING+DOWNCASTING](https://www.javatpoint.com/upcasting-and-downcasting-in-cpp)
\
![UP_DOWN_CASTING](https://i.imgur.com/3trTnzr.png)

<!----------------------------------------------------------------------------->
### **STATIC CAST**
---
<p>
	Simple conversion between direct values; Most simple and usual conversion.
	Helps UPCASTING and DOWNCASTING on known classes hierarchy + Avoid conversions between
	unrelated class hierarchy.
</p>

<!----------------------------------------------------------------------------->
### **DYNAMIC_CAST**
---
<p>
	Only cast during runtime (during execution). The others are during compilation.
	Can FAIL during execution.
	Verifies if the downcast is possible, or not.
	Conversion returns NULL when the conversion is not possible.
	OR throw() an exception std::bad_cast &bc, in the case we are using reference instead of pointer.

</p>

<!----------------------------------------------------------------------------->
### **REINTERPRET_CAST**
---
<p>
	The most permissive. Including the consequences.
	Only guarantees that if you cast a pointer to a different type, and then reinterpret_cast it back to the original type, you get the original value.

</p>

<!----------------------------------------------------------------------------->
### **CONST CAST**
---
<p>
	Used to remove the const-ness from references and pointers that ultimately refer to something that is not const.
</p>


<!----------------------------------------------------------------------------->
