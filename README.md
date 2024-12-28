# NoByte Language
More information to come in time...

# Practice Language called NoByte (Working title)
Practice language called NoByte. Named so after our little dog that just won't stop biting people's anckles. Used for practice to develop a programming language in C++ with all the fun tools in CICD and documentation.

## Tool Chain
* [Clang-18](https://github.com/llvm/llvm-project/releases/tag/llvmorg-18.1.8)
* [Clang-Tidy](https://clang.llvm.org/extra/clang-tidy/)
* [Clang-Format](https://clang.llvm.org/docs/ClangFormat.html)
* [Valgrind](https://valgrind.org/downloads/)
* [CMake](https://cmake.org/download/)
* [Python >=3.10](https://www.python.org/downloads/)
* [Conan2](https://conan.io/downloads)
* [Conan_Package:GTest](https://conan.io/center/recipes/gtest?version=1.14.0)
* [Git](https://git-scm.com/downloads)

For installing LLVM, it is faster to use the [LLVM script](https://apt.llvm.org/llvm.sh) to get all the tools used. 

_Note: The above script is targetting Ubuntu/Debian so if you're using another image, then it's best to install them manually._ 

Here is a quick one liner if you're feeling brave: `wget https://apt.llvm.org/llvm.sh && chmod +x llvm.sh && sudo ./llvm.sh 18 all`

## Development
### Definition of Done
* 100% tests pass
* Acceptance criteria completed unless Team Lead allows a change to the ticket
* All linter warnings are addressed
* Used Modern C++ features when possible 
* Program MUST build

### Merge Requests
This project follows git flow. This means feature branches merge into develop. Releases are created off develop and is it's own temprary branch. This branch is tested, versions are updated, and all fixes are applied. Release branches are named after semantic version of the current release version. Once completed the release branch is merged into both develop and main branch. Finally a tag of the release version is created off the merge of the release branch into the main branch commit hash.
#### Submitting
When submitting a merge request, make the merge requests (MR) as small as possible. This means a ticket can have multiple MRs into develop and non-breaking work can be added as well. When submitting MR, fill out the descriptions with the work, tests taken to confirm the work has finished, and any relevant notes. 

MRs that mentions "WIP (Work In Progress)" will be declined. WIP on MR is considered WIP MR and no WIP MR should be submitted. It's not proper to do active development in MRs. Only submit MR when they are ready to be pushed into develop. Non-breaking, working features, empty classes, unreferenced classes, etc are accepted as long as it fits DOD. 
#### Conducting
When reviewing MRs you will need to confirm DOD has been satisified.

### Committing
Follow the [Conventional Commits](https://www.conventionalcommits.org/en/v1.0.0/) when possible for MRs.

### Environments
#### Local
As the title suggests, local will require you install the tool chain for compiling the compiler for SHL.
#### Coder (Suggested)
Refer to the [Coder Templates](https://github.com/markbrown87/devops-coder) which houses the docker file and the coder templates for building a language in C++. 

### Compilation
To compile the language, just run the build.sh script.
To Run the language, just run the run.sh script.
To clean up your workspace of genereated folders/files, just run the clean.sh script.

## Documentation
User documentation is worked on under the "documentation" branch. Auto deployment has not be setup yet but will be coming in time.

## Usage
Once compiled, executing the run.sh is the easiest way to test. Manually, means you just execute "{ROOT}/build/bin/NoByte" to create the compiler.

## Contributing
To contribute to this project, just reach out to Mark Brown and he will setup you up to help. If there are issues or suggested improvements, submit them to the issue board backlog. They will be addressed and worked from there.