pipeline {
    agent any

    stages {

        stage('Build Application') {
            steps {
                echo "Compiling calculator application..."
                sh 'g++ src/main.cpp src/calculator.cpp -o calculator'
            }
        }

        stage('Run Unit Tests') {
            steps {
                echo "Running unit tests..."
                sh 'g++ src/calculator.cpp tests/test_calculator.cpp -o test'
                sh './test'
            }
        }

        stage('Docker Build') {
            steps {
                echo "Building Docker image..."
                sh '/opt/homebrew/bin/docker build -t scientific-calculator .'
            }
        }

    }

    post {
        success {
            echo 'Pipeline executed successfully!'
        }

        failure {
            echo 'Pipeline failed. Check logs.'
        }
    }
}