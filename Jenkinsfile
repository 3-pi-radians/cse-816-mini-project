pipeline {
    agent any

    environment {
        PATH = "/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"
    }

    stages {

        stage('Build') {
            steps {
                echo "Building the project..."
                sh 'make build'
            }
        }

        stage('Test') {
            steps {
                echo "Running tests..."
                sh 'make test'
            }
        }

        stage('Docker Build') {
            steps {
                echo
                sh 'docker build -t scientific-calculator .'
            }
        }

    }
}