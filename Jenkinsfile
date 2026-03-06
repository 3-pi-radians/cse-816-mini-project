pipeline {
    agent any

    stages {

    stage('Clone Repository') {
        steps {
            git branch: 'main',
            url: 'https://github.com/3-pi-radians/cse-816-mini-project.git'
        }
    }

    stage('Build') {
                steps {
                    echo "Compiling calculator source code..."
                    sh 'g++ src/calculator.cpp -o calculator'
                }
            }

            stage('Test') {
                steps {
                    echo "Running unit tests..."
                    sh 'g++ src/calculator.cpp tests/test_calculator.cpp -o test'
                    sh './test'
                }
            }

            stage('Docker Build') {
                steps {
                    echo "Building Docker image..."
                    sh 'docker build -t scientific-calculator .'
                }
            }
        }
}