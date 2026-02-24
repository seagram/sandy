const std = @import("std");

pub fn build(b: *std.Build) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const mod = b.createModule(.{
        .target = target,
        .optimize = optimize,
        .link_libcpp = true,
    });

    mod.addCSourceFiles(.{
        .files = &.{
            "src/main.cpp",
        },
        .flags = &.{"-std=c++17"},
    });

    const exe = b.addExecutable(.{
        .name = "sandy",
        .root_module = mod,
    });

    b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());

    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Build and run sandy");
    run_step.dependOn(&run_cmd.step);
}
