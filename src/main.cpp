#include <cstdint>
#include <spawn.h>
#include <string>

/* NOTICE:
 * The following is taken from Apple's sandbox.h file:
 * "This header is deprecated and may be removed in a future release.
 * Developers who wish to sandbox an app should instead adopt the App Sandbox
 * feature described in the App Sandbox Design Guide."
 */
#include <sandbox.h>

class PosixSpawn {
public:
  pid_t pid;
  const char *path;
  const posix_spawn_file_actions_t *file_actions;
  const posix_spawnattr_t *attrp;
  const char **envp;
  const char **argv;
  PosixSpawn() {} // TODO
  int exec() {}   // TODO
};

int main(int argc, char *argv[]) {
  const std::string command = "ls";
  const char *profile = "(version 1)\n(allow default)\0";
  const uint64_t flags = 0;
  char *errorbuf = nullptr;

  /* sandbox_init()
   * Places the current process in a sandbox with a profile as
   * specified.  If the process is already in a sandbox, the new profile
   * is ignored and sandbox_init() returns an error.
   */

  return sandbox_init(profile, flags, &errorbuf);
}
