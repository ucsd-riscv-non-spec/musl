.text
.global __tlsdesc_static
.hidden __tlsdesc_static
.type __tlsdesc_static,%function
__tlsdesc_static:
	ld a0,8(a0)
	bmovs b0, .__tlsdesc_static_jr_t0
	bmovt b0, t0, 0
.__tlsdesc_static_jr_t0:
	pb b0

.global __tlsdesc_dynamic
.hidden __tlsdesc_dynamic
.type __tlsdesc_dynamic,%function
__tlsdesc_dynamic:
	add sp,sp,-16
	sd t1,(sp)
	sd t2,8(sp)

	ld t2,-8(tp) # t2=dtv

	ld a0,8(a0)  # a0=&{modidx,off}
	ld t1,8(a0)  # t1=off
	ld a0,(a0)   # a0=modidx
	sll a0,a0,3  # a0=8*modidx

	add a0,a0,t2 # a0=dtv+8*modidx
	ld a0,(a0)   # a0=dtv[modidx]
	add a0,a0,t1 # a0=dtv[modidx]+off
	sub a0,a0,tp # a0=dtv[modidx]+off-tp

	ld t1,(sp)
	ld t2,8(sp)
	add sp,sp,16
	bmovs b0, .__tlsdesc_dynamic_jr_t0
	bmovt b0, t0, 0
.__tlsdesc_dynamic_jr_t0:
	pb b0

