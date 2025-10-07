# Stanford CS144 Labs

官网（我采用的是 2025 Winter 版本，所以只能给出 Wayback Machine 的链接）：<https://web.archive.org/web/20250917125027/https://cs144.github.io/>


## 进度

- [x] Checkpoint 0: Networking Warmup
    - mac 上建议直接用官方提供的 UTM 虚拟机，这样不太折腾
    - 由于不是 Stanford 的师生，部分环节可能无法实现，比如涉及到学号的部分
    - 有部分对现代 C++ 的介绍，里面给出的一些经验法则值得学习
    - 本次实验的重点在后半段，要求实现 webget 函数，以及内存中的可靠字节流
        - 补全代码前，需要对已有的代码框架有一个清晰的认识和理解，不然举步维艰（悲）

- [ ] Checkpoint 1: Stitching Substrings into a Byte Stream
- [ ] Checkpoint 2: The TCP Receiver
- [ ] Checkpoint 3: The TCP Sender
- [ ] Checkpoint 4: Measuring the Real World
- [ ] Checkpoint 5: Down the Stack (the Network Interface)
- [ ] Checkpoint 6: Building an IP Router
- [ ] Checkpoint 7: Putting It All Together


## 注意事项


## 感想


## 原 README.md 的内容

Stanford CS 144 Networking Lab
<!-- ============================== -->

These labs are open to the public under the (friendly) request that to
preserve their value as a teaching tool, solutions not be posted
publicly by anybody.

Website: https://cs144.stanford.edu

To set up the build system: `cmake -S . -B build`

To compile: `cmake --build build`

To run tests: `cmake --build build --target test`

To run speed benchmarks: `cmake --build build --target speed`

To run clang-tidy (which suggests improvements): `cmake --build build --target tidy`

To format code: `cmake --build build --target format`
