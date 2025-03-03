# Lab 1: Verification of Fisher’s Lemma Using Simulated Data from Normal Distributions								
# Fisher’s Exact Test is used to determine if there are nonrandom associations between two categorical variables,
# especially when sample sizes are small or the expected frequency is less than 5.

# Parameters								
mu <- 5						#	Mean of the normal distribution.	
sigma <- 2				# Standard deviation of the normal distribution				
n <- 30           #Sample size for each simulation
N_sim <- 1000     #Number of simulations.

# Initialize vectors								
sample_means <- numeric(N_sim)								
sample_vars <- numeric(N_sim)		
# Creates two empty numeric vectors of length N_sim to store sample means and sample variances.					
								
# Monte Carlo Simulation							
set.seed(123)								
for (i in 1:N_sim) 
{								
  data <- rnorm(n, mean = mu, sd = sigma)		 # Generates n random numbers from a normal distribution 						
  sample_means[i] <- mean(data)								
  sample_vars[i] <- var(data)								
}								
								
# Compute Correlation Between Sample Mean and Sample Variance							
correlation <- cor(sample_means, sample_vars)			 #Computes Pearson’s correlation coefficient.					
print(paste("Correlation between sample mean and sample variance:", correlation))	
# Computes the correlation between sample_means and sample_vars using Pearson’s correlation coefficient.
# Displays the correlation value.							
								
# Graphical Output								
par(mfrow = c(2, 2))	
# Divides the plotting area into a 2×2 grid for four plots.							
								
# Histogram of sample means								
hist(sample_means, breaks = 30, col = "lightblue", main = "Distribution of Sample Means", xlab = "Sample Mean", border = "white")								
curve(dnorm(x, mean = mu, sd = sigma/sqrt(n)), add = TRUE, col = "red", lwd = 2)								
								
# Histogram of sample variances								
hist(sample_vars, breaks = 30, col = "lightgreen", main = "Distribution of Sample Variances", xlab = "Sample Variance", border = "white")								
curve(dchisq((x * (n-1)) / sigma^2, df = n-1) * (n-1)/sigma^2, add = TRUE, col = "blue", lwd = 2)								
								
# Scatterplot of sample means vs. sample variances								
plot(sample_means, sample_vars, pch = 19, col = rgb(0, 0, 1, 0.5), main = "Sample Mean vs. Sample Variance", xlab = "Sample Mean", ylab = "Sample Variance")								
abline(h = sigma^2, col = "red", lwd = 2)								
								
# Q-Q plot for sample means								
qqnorm(sample_means, main = "Q-Q Plot for Sample Means", col = "blue")								
qqline(sample_means, col = "red", lwd = 2)
