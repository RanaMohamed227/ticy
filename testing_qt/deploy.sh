#!/bin/bash

# Set variables
REPO_URL="https://github.com/your-username/your-repo.git"
PROJECT_DIR="your-project-directory"
BUILD_DIR="build"
DEPLOY_DIR="deploy"

# Function to check the last command status and exit if it failed
check_status() {
    if [ $? -ne 0 ]; then
        echo "Error: $1 failed"
        exit 1
    fi
}

# Pull the latest code
echo "Pulling the latest changes..."
git pull origin main
check_status "git pull"

# Create build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

cd "$BUILD_DIR" || exit

# Generate Makefile and build the project
echo "Building the project..."
qmake ../main.pro
check_status "qmake"

make
check_status "make"

# Run tests (if you have any test scripts or binaries)
if [ -f "tests/test_script.sh" ]; then
    echo "Running tests..."
    ./tests/test_script.sh
    check_status "tests"
fi

# Deployment steps
# Example: Create deployment directory if it doesn't exist
if [ ! -d "$DEPLOY_DIR" ]; then
    mkdir "$DEPLOY_DIR"
fi

# Copy the build artifacts to the deployment directory
echo "Deploying the build..."
cp your_binary "$DEPLOY_DIR"
check_status "deployment"

echo "Build and deployment completed successfully."
