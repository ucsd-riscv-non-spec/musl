#define a_barrier a_barrier
static inline void a_barrier()
{
	__asm__ __volatile__ ("fence rw,rw" : : : "memory");
}

#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
	int old, tmp;
	__asm__ __volatile__ (
		"	bmovs b30, 2f\n"
		"	bmovs b31, 3f\n"
		"	bmovt b30, 4f\n"
		"	bmovt b31, 1f\n"
		"1:\n"
		"	lr.w.aqrl %0, (%2)\n"
		"	bmovc_bne b30, %0, %3\n"
		"2:\n"
		"	pb b30\n"
 		"	sc.w.aqrl %1, %4, (%2)\n"
		"	bmovc_bne b31, %1, zero\n"
		"3:\n"
		"	pb b31\n"
		"4:\n"
		: "=&r"(old), "=&r"(tmp)
		: "r"(p), "r"((long)t), "r"((long)s)
		: "memory");
	return old;
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
	void *old;
	int tmp;
	__asm__ __volatile__ (
		"\n1:	lr.d.aqrl %0, (%2)\n"
		"	bne %0, %3, 1f\n"
		"	sc.d.aqrl %1, %4, (%2)\n"
		"	bnez %1, 1b\n"
		"1:"
		: "=&r"(old), "=&r"(tmp)
		: "r"(p), "r"(t), "r"(s)
		: "memory");
	return old;
}
