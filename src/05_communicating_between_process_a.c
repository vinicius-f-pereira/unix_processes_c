int	main(int argc, char **argv)
{
	/* fd var needed to store result from pipe function */
	int	fd[2];
	/* to create (open) a pipe, just need to call pipe function */
	/* pipe() -> create a one-way communication channel */
	/* 	if successful, two file descriptors are stored in PIPEDES */
	/* 		bytes written on PIPEDES[1] can be read from PIPEDES[0] */
	/* 			return 0 if successful, -1 if not. */
	pipe(fd);
	return (0);
}
