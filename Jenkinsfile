pipeline {
    agent any

    environment {
        PATH = "/opt/homebrew/bin:/usr/local/bin:/usr/bin:/bin:/usr/sbin:/sbin"
    }

    stages {

        stage('Build') {
            steps {
                echo "Building calculator..."
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
                echo "Building Docker image..."
                sh '/opt/homebrew/bin/docker build -t scientific-calculator .'
            }
        }

    }

    post {
        success {
            echo "Pipeline completed successfully"
        }

        failure {
            echo "Pipeline failed"
        }
    }
}