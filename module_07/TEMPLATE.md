# C++ TEMPLATES

**<u> INTRODUCTION VIDEO (00) </u>**

[cppreference.com](https://en.cppreference.com/w/cpp/language/templates)
\
[cplusplus.com](https://cplusplus.com/doc/oldtutorial/templates/)

1. Huge potential synthax
2. Used to write code which will be generated at compilation time.
3. The ancestor of templates are parametertized macros.
4. Particular synthax to learn. Not too complicated, but can become very complex.

---
\
**<u> TEMPLATES (01) </u>**

```c++

	/// @brief This function can only be used with integers.
	int	max( int x, int y ) {
		return ( x >= y ? x : y );
	}

```

```c++

	template< typename T >
	T	const &max( const T &x, const T &y ) {
		return ( x >= y ? x : y );
	}

```
* T could be an overload operands from a class instance.
* 'template<>' is a keyword to inform the compiler that this is a template.
* Template are like autocompletion/generative code. It is not a function, not a class. It is a model to set instructions to how to build.

---
\
**<u> DEFAULT TYPE (02) </u>**

* Naming convesion: write file.tpp (foor template)
	* Can vary from persons to persons

```c++

	template< typename T = float > // By default, the template is a float parameter.
	class	Vertex {

		private:
			const T x;
			const T y;
			const T z;

		public:
			Vertex(const T &x, const T &y, const T &z) :
			_x( x ),
			_y( y ),
			_z( z ) {};
			~Vertex( void ) {};

		const T &getX( void ) const { return (this->x) };
		const T &getY( void ) const { return (this->y) };
		const T &getZ( void ) const { return (this->z) };
	};	/*	Vertex	*/

///------------------------------------------------ @category OPERAND.S OVERLOAD

	template< typename T >
	std::ostream &operator<<( std::ostream &output, const Vertex< T > &v) {
		std::cout.precision( 1 );
		output	<< setiosflags( std::ios::fixed );
		output	<< "VERTEX: x[";
		output	<< v.getX() << "], [" << v.getY() << "], [" << v.getY()
			<< "]" << std::endl;
		return ( output );
	}
```

---
\
**<u> SPECIALIZATION </u>**

1. New synthax for more specific behavior of the template.
2. Do not hesitate to use typedef to simplify the code.
3. 

---
\
