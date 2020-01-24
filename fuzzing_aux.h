extern char *inputFile;

extern int fd_inputFile;

extern FILE *myLogFile;

//extern unsigned int tapping;

extern int inputFileDescriptor;

extern char *outputFile;

int readFile(const char *filePath, uint8_t **buffer);

static inline void do_chown (const char *file_path,
               const char *user_name,
               const char *group_name)
{
  uid_t          uid;
  gid_t          gid;
  struct passwd *pwd;
  struct group  *grp;

  pwd = getpwnam(user_name);
  if (pwd == NULL) {
	  fprintf(stderr, "Failed to get uid");
	  exit(EXIT_FAILURE);
  }
  uid = pwd->pw_uid;

  grp = getgrnam(group_name);
  if (grp == NULL) {
	  fprintf(stderr, "Failed to get gid");
      exit(EXIT_FAILURE);
  }
  gid = grp->gr_gid;

  if (chown(file_path, uid, gid) == -1) {
	  fprintf(stderr, "chown fail");
      exit(EXIT_FAILURE);
  }
}
