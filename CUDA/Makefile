# Simple Makefile for CUDA Matrix Multiplication

NVCC = nvcc
CFLAGS = -O3 -arch=sm_75
TARGET = cuda_matrixmul
SOURCE = cuda_matrixmul.cu

# Default target
all: $(TARGET)

# Build the program
$(TARGET): $(SOURCE)
	$(NVCC) $(CFLAGS) -o $@ $<

# Debug build
debug: $(SOURCE)
	$(NVCC) -g -G -o $(TARGET)_debug $<

# Clean build files
clean:
	rm -f $(TARGET) $(TARGET)_debug

# Rebuild
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Help
help:
	@echo "Available targets:"
	@echo "  all     - Build the program (default)"
	@echo "  debug   - Build debug version"
	@echo "  clean   - Remove build files"
	@echo "  rebuild - Clean and build"
	@echo "  run     - Build and run the program"
	@echo "  help    - Show this help"

.PHONY: all debug clean rebuild run help
check-cuda:
	@echo "=== CUDA Installation Check ==="
	@echo "NVCC Version:"
	@nvcc --version 2>/dev/null || echo "❌ NVCC not found - install CUDA Toolkit"
	@echo ""
	@echo "NVIDIA Driver:"
	@nvidia-smi --version 2>/dev/null || echo "❌ NVIDIA driver not found"
	@echo ""
	@echo "Available GPUs:"
	@nvidia-smi --list-gpus 2>/dev/null || echo "❌ No CUDA-capable GPUs found"
	@echo ""
	@echo "GPU Compute Capability:"
	@nvidia-smi --query-gpu=name,compute_cap --format=csv 2>/dev/null || echo "❌ Cannot query GPU information"

# Memory usage analysis
.PHONY: memory-info
memory-info:
	@echo "=== GPU Memory Information ==="
	@nvidia-smi --query-gpu=memory.total,memory.used,memory.free --format=csv || echo "Cannot access GPU memory info"

# Clean build files
.PHONY: clean
clean:
	rm -f $(TARGET) $(TARGET)_debug $(TARGET)_opt $(TARGET)_multi
	rm -f *.o *.ptx
	@echo "✓ Cleaned build files"

# Deep clean including profiler output
.PHONY: clean-all
clean-all: clean
	rm -f nvprof_output.* *.nvvp *.qdrep
	@echo "✓ Cleaned all generated files"

# Install CUDA program (requires sudo)
.PHONY: install
install: $(TARGET)
	@echo "Installing $(TARGET) to /usr/local/bin..."
	@sudo cp $(TARGET) /usr/local/bin/
	@echo "✓ Installation complete"

# Show help information
.PHONY: help
help:
	@echo "CUDA Matrix Multiplication Makefile"
	@echo "=================================="
	@echo ""
	@echo "Available targets:"
	@echo "  all         - Build optimized version (default)"
	@echo "  debug       - Build debug version with CUDA debugging"
	@echo "  optimized   - Build with maximum optimization"
	@echo "  multi-arch  - Build for multiple GPU architectures"
	@echo "  run         - Build and run with test input"
	@echo "  test        - Run performance tests with different sizes"
	@echo "  benchmark   - Comprehensive performance benchmark"
	@echo "  profile     - Profile application with nvprof"
	@echo "  check-cuda  - Check CUDA installation and GPU availability"
	@echo "  memory-info - Display GPU memory information"
	@echo "  clean       - Remove build files"
	@echo "  clean-all   - Remove all generated files"
	@echo "  install     - Install to system (requires sudo)"
	@echo "  help        - Show this help message"
	@echo ""
	@echo "Compiler settings:"
	@echo "  NVCC        = $(NVCC)"
	@echo "  CFLAGS      = $(CFLAGS)"
	@echo "  ARCH_FLAGS  = $(ARCH_FLAGS)"
	@echo ""
	@echo "Usage examples:"
	@echo "  make                    # Build optimized version"
	@echo "  make debug             # Build debug version"
	@echo "  make test              # Run performance tests"
	@echo "  make ARCH_FLAGS=-arch=sm_75  # Build for specific GPU"
	@echo ""
	@echo "GPU Architecture Guide:"
	@echo "  sm_35  - Kepler (GTX 600/700 series)"
	@echo "  sm_50  - Maxwell (GTX 900 series)"
	@echo "  sm_61  - Pascal (GTX 1000 series)"
	@echo "  sm_75  - Turing (RTX 2000 series)"
	@echo "  sm_80  - Ampere (RTX 3000 series)"

# Show system information
.PHONY: info
info:
	@echo "=== System Information ==="
	@echo "Operating System: $$(uname -s)"
	@echo "Architecture: $$(uname -m)"
	@echo "CUDA Toolkit: $$(nvcc --version | grep release | cut -d' ' -f6 2>/dev/null || echo 'Not found')"
	@echo "GPU Model: $$(nvidia-smi --query-gpu=name --format=csv,noheader 2>/dev/null || echo 'Not detected')"
	@echo "GPU Memory: $$(nvidia-smi --query-gpu=memory.total --format=csv,noheader 2>/dev/null || echo 'Not detected')"
	@echo "Compute Capability: $$(nvidia-smi --query-gpu=compute_cap --format=csv,noheader 2>/dev/null || echo 'Not detected')"
	@echo "Driver Version: $$(nvidia-smi --query-gpu=driver_version --format=csv,noheader 2>/dev/null || echo 'Not detected')"

.PHONY: all debug optimized multi-arch run test benchmark profile check-cuda memory-info clean clean-all install help info
