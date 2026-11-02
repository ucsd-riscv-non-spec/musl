#include "stdio_impl.h"

size_t __stdio_read(FILE *f, unsigned char *buf, size_t len)
{
	size_t len0 = len - !!f->buf_size;
	ssize_t cnt;

	if (len0) {
		cnt = syscall(SYS_read, f->fd, buf, len0);
		if (cnt <= 0) {
			f->flags |= cnt ? F_ERR : F_EOF;
			return 0;
		}
		if ((size_t)cnt < len0) return cnt;
	} else {
		cnt = 0;
	}

	if (f->buf_size) {
		ssize_t cnt2 = syscall(SYS_read, f->fd, f->buf, f->buf_size);
		if (cnt2 <= 0) {
			if (len0) return cnt;
			f->flags |= cnt2 ? F_ERR : F_EOF;
			return 0;
		}
		f->rpos = f->buf;
		f->rend = f->buf + cnt2;
		buf[len-1] = *f->rpos++;
		return len;
	}

	return cnt;
}
