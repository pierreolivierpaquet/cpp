
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
	int		a = 42;
	double	b = a;			// Implicit conversion cast

	double	d = a;			// Implicit promotion. SAFE
	int		e = d;			// Implicit demotion. RISK: bit truncation, precision loss, data loss.
	```
	* 64bits are used to store a DOUBLE / 32 bits are used to store an INT
	* 

2. <u> **EXPLICIT CONVERSION CAST.** </u>\
	This occurs when the programmer explicitly specifies a type conversion using a cast operator.
	```c
	int		a = 42;
	double	c = (double)a;	// Explicit conversion
	int		f = (int)d; 	// Explicit demotion. SAFE: Same as implicit, but done voluntarily.
	```
3. <u> **REINTERPRETATION CONVERSION. </u>**\
	Conversion where the source type and the target type are the same, resulting in no actual conversion being performed. Reinterpretation typically doesn't involve modifying or reorganizing the bits in memory; instead, it involves treating the existing memory layout of an object as if it were of a different type.
	```c
	float	a	=	42.9876f;

	void	*b	=	&a;	// Implicit reinterpretation cast.
	void	*c	=	(void *) &a;	// Explicit reinterpretation cast.

	void	*d	=	&a;	// Implicit promotion. SAFE
	int		*e	=	d;	// Implicit demotion. RISKY: Arbitrary cast, data loss.
	int		*f	=	(int *)d;	// Explicit demotion: SAFE: Voluntarily cast.
	```


<!----------------------------------------------------------------------------->
### **STATIC CAST**
---
<p>
	
</p>

<!----------------------------------------------------------------------------->
### **CONST CAST**
---
<p>
	
</p>

<!----------------------------------------------------------------------------->
### **REINTERPRET_CAST**
---
<p>
	
</p>

<!----------------------------------------------------------------------------->
### **DYNAMIC_CAST**
---
<p>
	
</p>

<!----------------------------------------------------------------------------->
