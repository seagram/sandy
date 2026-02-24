#include <cstdint>
#include <string>

/* NOTICE:
 * The following is taken from Apple's sandbox.h file:
 * "This header is deprecated and may be removed in a future release.
 * Developers who wish to sandbox an app should instead adopt the App Sandbox
 * feature described in the App Sandbox Design Guide."
 */
#include <sandbox.h>

int main(int argc, char *argv[]) {
  const std::string command = "ls";
  const char *profile = "(version 1)\n(allow default)\0";
  const uint64_t flags = 0;
  char *errorbuf = nullptr;
  return sandbox_init(profile, flags, &errorbuf);
}
