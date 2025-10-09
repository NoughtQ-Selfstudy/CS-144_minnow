# Stanford CS144 Labs

官网（我采用的是 2025 Winter 版本，所以只能给出 Wayback Machine 的链接）：<https://web.archive.org/web/20250917125027/https://cs144.github.io/>


## 进度

- [x] Checkpoint 0: Networking Warmup
    - mac 上建议直接用官方提供的 UTM 虚拟机，这样不太折腾
    - 由于不是 Stanford 的师生，部分环节可能无法实现，比如涉及到学号的部分
    - 有部分对现代 C++ 的介绍，里面给出的一些经验法则值得学习
    - 本次实验的重点在后半段，要求实现 webget 函数，以及内存中的可靠字节流
        - 补全代码前，需要对已有的代码框架有一个清晰的认识和理解，不然举步维艰（悲）

- [x] Checkpoint 1: Stitching Substrings into a Byte Stream
    - 好像今年新增动手环节，但同样由于无法访问 Stanford 的内网所以无法实现（`apps/ip_raw.cc`）
    - 一些经验：
        - FAQs 上面的那幅图很重要，在尝试实现代码前请务必理解清楚（~~不要像我一样还没理解清楚就上去莽做，搞了半天发现题目理解错了~~）
        - 数据结构的选择很关键——提示一下，不是很复杂的数据结构，而且 C++ 提供了 API 的（~~废话，大多数常见的数据结构都有 API 的~~）
        - 个人觉得最困难的地方是合并临时存储在 `Reassembler` 内的子字符串
        - 无论输入是什么样的，它们的并集永远是同一个字符串
        - 整体逻辑完成后，可通过运行 `cmake --build build --target check1`，通过测试单元来找 bug
    

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
